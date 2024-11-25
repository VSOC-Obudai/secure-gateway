/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "can.h"

#include "config.h"
#include "led.h"
#include "isr_config.h"
#include "spinlock.h"

#include <Can/Can/IfxCan_Can.h>
#include <Can/Std/IfxCan.h>
#include <IfxCpu_Irq.h>
#include <IfxPort_PinMap.h>
#include <SysSe/Bsp/Bsp.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/*****************************************************************************
 * Macros
 ****************************************************************************/

#define DEFAULT_CAN_PORT (CAN2_PORT)
#define DEFAULT_CAN_TX_PIN (CAN21_TX_PIN)
#define DEFAULT_CAN_RX_PIN (CAN21_RX_PIN)

#define CAN_BUFFER_SIZE (256)

/*****************************************************************************
 * Data structures
 ****************************************************************************/

typedef struct {
  IfxCan_Can base;
  IfxCan_Can_Node tx;
  IfxCan_Can_Node rx;
  IfxCan_LastErrorCodeType er;
  IfxCpu_spinLock lock;
} can_device_t;

typedef struct {
  uint32_t msg_sent;
  uint32_t msg_received;
  uint32_t msg_lost;
} can_debug_stats_t;

/*****************************************************************************
 * Constants
 ****************************************************************************/

static const IfxCan_Can_Pins default_can_pins = {
    .padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed2,
    .txPin = &DEFAULT_CAN_TX_PIN,
    .txPinMode = IfxPort_OutputMode_pushPull,
    .rxPin = &DEFAULT_CAN_RX_PIN,
    .rxPinMode = IfxPort_InputMode_pullUp};

/*****************************************************************************
 * Global variables
 ****************************************************************************/

can_device_t can_device;
can_debug_stats_t can_debug_stats;

/*****************************************************************************
 * Function prototypes
 ****************************************************************************/

static void _can_message_print(const char* const prefix, const can_frame_t* const msg);
static void _can_error_print(uint32_t error_code);
static void _can_init_device(void);
static void _can_init_source(void);
static void _can_init_sink(void);
static void _can_init_pins(void);
static void _can_accept_messages_in_range(uint32_t from_id, uint32_t to_id);
static void _can_install_interrupts(void);
static void _can_wait_until_connect(void);

/*****************************************************************************
 * Hardware interrupts
 ****************************************************************************/

IFX_INTERRUPT(can_irq_msg_sent, 0, ISR_PRIORITY_CAN_MSG_SENT) {
  can_debug_stats.msg_sent = (can_debug_stats.msg_sent + 1) % UINT32_MAX;
  led_toggle(&led_0);
  IfxCan_Node_clearInterruptFlag(can_device.tx.node, IfxCan_Interrupt_transmissionCompleted);
}

IFX_INTERRUPT(can_irq_msg_rcvd, 0, ISR_PRIORITY_CAN_MSG_RCVD) {
  can_frame_t frame;
  can_recv(&frame);
  can_debug_stats.msg_received = (can_debug_stats.msg_received + 1) % UINT32_MAX;
  led_toggle(&led_1);
  IfxCan_Node_clearInterruptFlag(can_device.rx.node, IfxCan_Interrupt_rxFifo0NewMessage);
}

IFX_INTERRUPT(can_irq_msg_lost, 0, ISR_PRIORITY_CAN_MSG_LOST) {
  can_debug_stats.msg_lost = (can_debug_stats.msg_lost + 1) % UINT32_MAX;
  led_toggle(&led_rgb_r);
  IfxCan_Node_clearInterruptFlag(can_device.rx.node, IfxCan_Interrupt_rxFifo0MessageLost);
}

IFX_INTERRUPT(can_irq_comm_error, 0, ISR_PRIORITY_CAN_ERROR) {
  uint32_t current_error_code = IfxCan_Node_getLastErroCodeStatus(can_device.rx.node);
  if (can_device.er != current_error_code) {
    can_device.er = current_error_code;
    _can_error_print(can_device.er);
    if (can_device.er != IfxCan_LastErrorCodeType_noError) {
      led_off(&led_rgb_g);
      led_toggle(&led_rgb_r);
    } else {
      led_off(&led_rgb_r);
      led_toggle(&led_rgb_g);
    }
  }
  IfxCan_Node_clearInterruptFlag(can_device.rx.node, IfxCan_Interrupt_protocolErrorData);
}

/*****************************************************************************
 * Function declarations
 ****************************************************************************/

static void _can_message_print(const char *const prefix, const can_frame_t *const frame) {
  spinlock_lock(&can_device.lock);
  printf("%s | 0x%08lX |", prefix, frame->can_id);
  for (uint8_t i = 0; i < frame->len; ++i) {
    printf(" %02X", frame->data[i]);
  }
  printf("\n");
  spinlock_unlock(&can_device.lock);
}

static void _can_error_print(uint32_t error_code) {
  static const char *error_strings[] = {
      "No errors (0): CAN device operates normally",
      "Bit stuffing error(1): invalid bit sequence was detected in CAN data stream. This may be due to noise or synchronization issues. Check the bus integrity and termination.",
      "Form error(2): Incorrect CAN frame format detected, possibly due to frame corruption. Verify the frame structure and bus communication.",
      "Ack error(3): No acknowledgement received for the transmitted CAN frame. Ensure that other nodes are connected and operational.",
      "Bit error(4): Expected to send a recessive bit (1) but read a dominant bit (0). Possible short circuit or bus contention. Inspect the wiring for shorts.",
      "Bit error(5): Expected to send a dominant bit (0) but read a recessive bit (1). Possible open circuit or disconnection. Check for loose connections.",
      "CRC error(6): The received CAN data failed the Cyclic Redundancy Check, indicating possible data corruption due to noise. Examine the network for interference.",
      "CAN bus error(7): The CAN controller has not detected any bus activity. Check if the bus is inactive, disconnected, or if there is a hardware issue."};
  if (error_code > 0) {
    spinlock_lock(&can_device.lock);
    printf("!! %s\n", error_strings[(uint32_t)can_device.er]);
    spinlock_unlock(&can_device.lock);
  }
}

static void _can_init_device(void) {
  IfxCan_Can_Config can_module_config;
  printf(".. Initializing CAN driver...\n");
  IfxCan_Can_initModuleConfig(&can_module_config, &DEFAULT_CAN_PORT);
  IfxCan_Can_initModule(&can_device.base, &can_module_config);
  printf("-- CAN driver ready!\n");
}

static void _can_init_source(void) {
  IfxCan_Can_NodeConfig can_node_config;

  printf(".. Initializing CAN TX ..\n");

  IfxCan_Can_initNodeConfig(&can_node_config, &can_device.base);

  /* Default node settings */
#ifdef LOOPBACK_MODE
#if LOOPBACK_MODE
  can_node_config.busLoopbackEnabled = TRUE;
#endif
#endif

  can_node_config.nodeId = IfxCan_NodeId_1;
  can_node_config.frame.type = IfxCan_FrameType_transmit;
  can_node_config.pins = &default_can_pins;

  /* Buffering */
  can_node_config.txConfig.txMode = IfxCan_TxMode_queue;
  can_node_config.txConfig.txBufferDataFieldSize = IfxCan_DataFieldSize_8;
  can_node_config.txConfig.txFifoQueueSize = 32;
  can_node_config.txConfig.txEventFifoSize = 0;
  can_node_config.txConfig.dedicatedTxBuffersNumber = 0;

  /* Interrupts */
  can_node_config.interruptConfig.transmissionCompletedEnabled = TRUE;
  can_node_config.interruptConfig.traco.priority = ISR_PRIORITY_CAN_MSG_SENT;
  can_node_config.interruptConfig.traco.interruptLine = IfxCan_InterruptLine_3;
  can_node_config.interruptConfig.traco.typeOfService = IfxSrc_Tos_cpu0;

  IfxCan_Can_initNode(&can_device.tx, &can_node_config);

  printf(".. CAN TX ready!\n");
}

static void _can_init_sink(void) {
  IfxCan_Can_NodeConfig can_node_config;

  printf(".. Initializing CAN RX ..\n");

  IfxCan_Can_initNodeConfig(&can_node_config, &can_device.base);

  /* Default node settings */
#ifdef LOOPBACK_MODE
#if LOOPBACK_MODE
  can_node_config.busLoopbackEnabled = TRUE;
#endif
#endif

  can_node_config.nodeId = IfxCan_NodeId_0;
  can_node_config.frame.type = IfxCan_FrameType_receive;
  can_node_config.pins = &default_can_pins;

  /* Filtering */
  can_node_config.filterConfig.messageIdLength = IfxCan_MessageIdLength_standard;
  can_node_config.filterConfig.standardListSize = 2;
  can_node_config.filterConfig.extendedListSize = 0;
  can_node_config.filterConfig.rejectRemoteFramesWithStandardId = 0;
  can_node_config.filterConfig.rejectRemoteFramesWithExtendedId = 0;
  can_node_config.filterConfig.standardFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_reject;
  can_node_config.filterConfig.extendedFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_reject;

  /* Buffering */
  can_node_config.rxConfig.rxMode = IfxCan_RxMode_fifo0; /* Reception */
  can_node_config.rxConfig.rxBufferDataFieldSize = IfxCan_DataFieldSize_8;
  can_node_config.rxConfig.rxFifo0DataFieldSize = IfxCan_DataFieldSize_8;
  can_node_config.rxConfig.rxFifo1DataFieldSize = IfxCan_DataFieldSize_8;
  can_node_config.rxConfig.rxFifo0OperatingMode = IfxCan_RxFifoMode_blocking;
  can_node_config.rxConfig.rxFifo1OperatingMode = IfxCan_RxFifoMode_blocking;
  can_node_config.rxConfig.rxFifo0WatermarkLevel = 0;
  can_node_config.rxConfig.rxFifo1WatermarkLevel = 0;
  can_node_config.rxConfig.rxFifo0Size = 32;
  can_node_config.rxConfig.rxFifo1Size = 0;

  /* Interrupts */
  can_node_config.interruptConfig.rxFifo0NewMessageEnabled = TRUE; /* Reception interrupts */
  can_node_config.interruptConfig.rxf0n.priority = ISR_PRIORITY_CAN_MSG_RCVD;
  can_node_config.interruptConfig.rxf0n.interruptLine = IfxCan_InterruptLine_2;
  can_node_config.interruptConfig.rxf0n.typeOfService = IfxSrc_Tos_cpu0;
  can_node_config.interruptConfig.rxFifo0MessageLostEnabled = TRUE;
  can_node_config.interruptConfig.alrt.priority = ISR_PRIORITY_CAN_MSG_LOST;
  can_node_config.interruptConfig.alrt.interruptLine = IfxCan_InterruptLine_1;
  can_node_config.interruptConfig.alrt.typeOfService = IfxSrc_Tos_cpu0;
  can_debug_stats.msg_received = 0;
  can_debug_stats.msg_sent = 0;
  can_debug_stats.msg_lost = 0;
  can_node_config.interruptConfig.protocolErrorDataEnabled = TRUE;
  can_node_config.interruptConfig.loi.priority = ISR_PRIORITY_CAN_COMM_ERROR;
  can_node_config.interruptConfig.loi.interruptLine = IfxCan_InterruptLine_0;
  can_node_config.interruptConfig.loi.typeOfService = IfxSrc_Tos_cpu0;
  can_device.er = 0;

  IfxCan_Can_initNode(&can_device.rx, &can_node_config);

  printf("-- CAN RX ready!\n");
}

static void _can_init_pins(void) {
  printf(".. Initializing CAN pins ..\n");

  IfxPort_setPinModeOutput(DEFAULT_CAN_TX_PIN.pin.port, DEFAULT_CAN_TX_PIN.pin.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
  IfxPort_setPinLow(DEFAULT_CAN_TX_PIN.pin.port, DEFAULT_CAN_TX_PIN.pin.pinIndex);

  IfxPort_setPinModeOutput(DEFAULT_CAN_RX_PIN.pin.port, DEFAULT_CAN_RX_PIN.pin.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
  IfxPort_setPinLow(DEFAULT_CAN_RX_PIN.pin.port, DEFAULT_CAN_RX_PIN.pin.pinIndex);

  IfxPort_setPinModeOutput(CAN_STB_PIN.port, CAN_STB_PIN.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
  IfxPort_setPinLow(CAN_STB_PIN.port, CAN_STB_PIN.pinIndex);

  printf("-- CAN pins ready!\n");
}

static void _can_init_leds(void) {
  printf(".. Initializing LEDs ..\n");

  led_init(&led_0);
  led_init(&led_1);
  led_init(&led_rgb_r);
  led_init(&led_rgb_g);
  led_init(&led_rgb_b);

  led_off(&led_0);
  led_off(&led_1);
  led_off(&led_rgb_r);
  led_off(&led_rgb_g);
  led_off(&led_rgb_b);

  printf("-- LEDs ready!\n");
}

static void _can_accept_messages_in_range(uint32_t from_id, uint32_t to_id) {
  IfxCan_Filter filter;

  filter.number = 0;
  filter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxFifo0;

  filter.type = IfxCan_FilterType_range;
  filter.id1 = from_id;
  filter.id2 = to_id;

  printf(".. Setting RX filters ..\n");

  IfxCan_Can_setStandardFilter(&can_device.rx, &filter);
  IfxCan_Can_setExtendedFilter(&can_device.rx, &filter);

  printf("-- RX filters set!\n");
}

static void _can_install_interrupts(void) {
  printf(".. Installing interrupts for CAN ..\n");

  IfxCpu_Irq_installInterruptHandler(&can_irq_msg_sent, ISR_PRIORITY_CAN_MSG_SENT);
  IfxCpu_Irq_installInterruptHandler(&can_irq_msg_rcvd, ISR_PRIORITY_CAN_MSG_RCVD);
  IfxCpu_Irq_installInterruptHandler(&can_irq_msg_lost, ISR_PRIORITY_CAN_MSG_LOST);
  IfxCpu_Irq_installInterruptHandler(&can_irq_comm_error, ISR_PRIORITY_CAN_COMM_ERROR);

  enableInterrupts();

  printf("-- CAN interrupts ready!\n");
}

static void _can_wait_until_connect(void) {
  uint32_t ec = UINT32_MAX;
  printf(".. Waiting for RX node ..\n");
  while (!IfxCan_Can_isNodeSynchronized(&can_device.rx)) {
    can_device.er = IfxCan_Node_getLastErroCodeStatus(can_device.rx.node);
    if (can_device.er != ec) {
      _can_error_print(can_device.er);
      ec = can_device.er;
    }
    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, POLL_INTERVAL_MS));
  }
  printf("-- RX node ready\n");
}

void can_init() {
  printf(".. Initializing CAN ..\n");

  _can_init_leds();
  _can_init_device();
  _can_init_pins();
  _can_init_source();
  _can_init_sink();
  _can_install_interrupts();
  _can_accept_messages_in_range(0x0000, 0xffff);

  _can_wait_until_connect();

  printf("-- CAN ready\n");
}

void can_send(can_frame_t *frame) {
  IfxCan_Status status = IfxCan_Status_ok;
  IfxCan_Message header;
  uint32_t payload[2];
  IfxCan_Can_initMessage(&header);
  header.storeInTxFifoQueue = TRUE;
  header.frameMode = IfxCan_FrameMode_standard;
  header.messageIdLength = IfxCan_MessageIdLength_standard;
  header.dataLengthCode = IfxCan_Node_getCodeFromDataLengthInBytes(frame->len);
  header.messageId = frame->can_id;
  payload[0] = frame->data[0];
  payload[0] |= frame->data[1] << 8;
  payload[0] |= frame->data[2] << 16;
  payload[0] |= frame->data[3] << 24;
  payload[1] = frame->data[4];
  payload[1] |= frame->data[5] << 8;
  payload[1] |= frame->data[6] << 16;
  payload[1] |= frame->data[7] << 24;
  do {
    status = IfxCan_Can_sendMessage(&can_device.tx, &header, payload);
  } while (status == IfxCan_Status_notSentBusy);
  _can_message_print("TX", frame);
}

void can_recv(can_frame_t *frame) {
  IfxCan_Message header;
  uint32_t payload[2];
  IfxCan_Can_initMessage(&header);
  header.frameMode = IfxCan_FrameMode_standard;
  header.messageIdLength = IfxCan_MessageIdLength_standard;
  header.readFromRxFifo0 = TRUE;
  IfxCan_Can_readMessage(&can_device.rx, &header, payload);
  frame->can_id = header.messageId;
  frame->len = IfxCan_Node_getDataLengthInBytes(header.dataLengthCode);
  frame->data[0] = (uint8_t)(payload[0]);
  frame->data[1] = (uint8_t)(payload[0] >> 8);
  frame->data[2] = (uint8_t)(payload[0] >> 16);
  frame->data[3] = (uint8_t)(payload[0] >> 24);
  frame->data[4] = (uint8_t)(payload[1]);
  frame->data[5] = (uint8_t)(payload[1] >> 8);
  frame->data[6] = (uint8_t)(payload[1] >> 16);
  frame->data[7] = (uint8_t)(payload[1] >> 24);
  _can_message_print("RX", frame);
}
