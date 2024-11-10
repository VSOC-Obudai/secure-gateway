/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "can.h"
#include "led.h"
#include "isr_config.h"
#include "spinlock.h"

#include <Can/Can/IfxCan_Can.h>
#include <Can/Std/IfxCan.h>
#include <IfxCpu_Irq.h>
#include <IfxPort_PinMap.h>
#include <SysSe/Bsp/Bsp.h>

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/*****************************************************************************
 * Macros
 ****************************************************************************/

#define DEFAULT_CAN_PORT (CAN2_PORT)
#define DEFAULT_CAN_TX_PIN (CAN20_TX_PIN)
#define DEFAULT_CAN_RX_PIN (CAN20_RX_PIN)

#define CAN_BUFFER_SIZE (256)

/*****************************************************************************
 * Data structures
 ****************************************************************************/

typedef struct {
  IfxCan_Can base;
  IfxCan_Can_Node source;
  IfxCan_Can_Node sink;
  IfxCan_LastErrorCodeType last_error;
  IfxCpu_spinLock lock;
} can_device_t;

typedef struct {
  uint32_t msg_sent_count;
  uint32_t msg_rcvd_count;
  uint32_t msg_lost_count;
} can_debug_stats_t;

/*****************************************************************************
 * Constants
 ****************************************************************************/

static const IfxCan_Can_Pins default_can_pins = {
    .padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed4,
    .txPin = &DEFAULT_CAN_TX_PIN,
    .txPinMode = IfxPort_OutputMode_pushPull,
    .rxPin = &DEFAULT_CAN_RX_PIN,
    .rxPinMode = IfxPort_InputMode_noPullDevice};

/*****************************************************************************
 * Global variables
 ****************************************************************************/

can_device_t can_device;
can_debug_stats_t can_debug_stats;

/*****************************************************************************
 * Function prototypes
 ****************************************************************************/

static void _can_message_print(const char* const prefix, const can_frame_t* const msg);
static void _can_error_print(void);
static void _can_init_device(void);
static void _can_init_source(void);
static void _can_init_sink(void);
static void _can_init_pins(void);
static void _can_accept_all_messages(void);
static void _can_install_interrupts(void);

/*****************************************************************************
 * Hardware interrupts
 ****************************************************************************/

IFX_INTERRUPT(can_irq_msg_sent, 0, ISR_PRIORITY_CAN_MSG_SENT) {
  can_debug_stats.msg_sent_count = (can_debug_stats.msg_sent_count + 1) % UINT32_MAX;
  led_toggle(&led_0);
  IfxCan_Node_clearInterruptFlag(can_device.source.node, IfxCan_Interrupt_transmissionCompleted);
}

IFX_INTERRUPT(can_irq_msg_rcvd, 0, ISR_PRIORITY_CAN_MSG_RCVD) {
  can_frame_t frame;
  can_recv(&frame);
  can_debug_stats.msg_rcvd_count = (can_debug_stats.msg_rcvd_count + 1) % UINT32_MAX;
  led_toggle(&led_1);
  IfxCan_Node_clearInterruptFlag(can_device.sink.node, IfxCan_Interrupt_rxFifo0NewMessage);
}

IFX_INTERRUPT(can_irq_msg_lost, 0, ISR_PRIORITY_CAN_MSG_LOST) {
  can_debug_stats.msg_lost_count = (can_debug_stats.msg_lost_count + 1) % UINT32_MAX;
  led_toggle(&led_rgb_r);
  IfxCan_Node_clearInterruptFlag(can_device.sink.node, IfxCan_Interrupt_rxFifo0MessageLost);
}

IFX_INTERRUPT(can_irq_comm_error, 0, ISR_PRIORITY_CAN_ERROR) {
  can_device.last_error = IfxCan_Node_getLastErroCodeStatus(can_device.sink.node);
  if (can_device.last_error != IfxCan_LastErrorCodeType_noError) {
    _can_error_print();
    led_off(&led_rgb_g);
    led_toggle(&led_rgb_r);
  } else {
    led_off(&led_rgb_r);
    led_toggle(&led_rgb_g);
  }
  IfxCan_Node_clearInterruptFlag(can_device.sink.node, IfxCan_Interrupt_protocolErrorData);
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

static void _can_error_print(void) {
  static const char *error_strings[] = {
      "CAN device is operating normally",
      "Bit stuffing error: invalid bit sequence detected in CAN data stream",
      "Form error: bad CAN frame format",
      "Ack error: no acknowledgement received for transmitted CAN frame",
      "Bit error: expected to write 1 but read 0",
      "Bit error: expected to write 0 but read 1",
      "CRC error: possibly corrupted CAN data",
      "No CAN bus event occurred"};
  uint32_t error_code = can_device.last_error;
  if (error_code > 0) {
    printf("ERROR: %s\n", error_strings[(uint32_t)can_device.last_error]);
  }
}

static void _can_init_device(void) {
  IfxCan_Can_Config can_module_config;
  IfxCan_Can_initModuleConfig(&can_module_config, &DEFAULT_CAN_PORT);
  IfxCan_Can_initModule(&can_device.base, &can_module_config);
  printf("-- CAN: base ready\n");
}

static void _can_init_source(void) {
  IfxCan_Can_NodeConfig can_node_config;
  IfxCan_Can_initNodeConfig(&can_node_config, &can_device.base);

  //can_node_config.busLoopbackEnabled = TRUE;

  can_node_config.nodeId = IfxCan_NodeId_0;
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

  IfxCan_Can_initNode(&can_device.source, &can_node_config);

  printf("-- CAN: TX ready\n");
}

static void _can_init_sink(void) {
  IfxCan_Can_NodeConfig can_node_config;
  IfxCan_Can_initNodeConfig(&can_node_config, &can_device.base);

  /* Node */
  //can_node_config.busLoopbackEnabled = TRUE;
  can_node_config.nodeId = IfxCan_NodeId_1;
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
  can_debug_stats.msg_rcvd_count = 0;
  can_debug_stats.msg_sent_count = 0;
  can_debug_stats.msg_lost_count = 0;
  can_node_config.interruptConfig.protocolErrorDataEnabled = TRUE;
  can_node_config.interruptConfig.loi.priority = ISR_PRIORITY_CAN_COMM_ERROR;
  can_node_config.interruptConfig.loi.interruptLine = IfxCan_InterruptLine_0;
  can_node_config.interruptConfig.loi.typeOfService = IfxSrc_Tos_cpu0;
  can_device.last_error = 0;

  IfxCan_Can_initNode(&can_device.sink, &can_node_config);

  printf("-- CAN: RX ready\n");
}

static void _can_init_pins(void) {
  IfxPort_setPinModeOutput(DEFAULT_CAN_TX_PIN.pin.port, DEFAULT_CAN_TX_PIN.pin.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
  IfxPort_setPinLow(DEFAULT_CAN_TX_PIN.pin.port, DEFAULT_CAN_TX_PIN.pin.pinIndex);

  IfxPort_setPinModeOutput(DEFAULT_CAN_RX_PIN.pin.port, DEFAULT_CAN_RX_PIN.pin.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
  IfxPort_setPinLow(DEFAULT_CAN_RX_PIN.pin.port, DEFAULT_CAN_RX_PIN.pin.pinIndex);

  IfxPort_setPinModeOutput(CAN_STB_PIN.port, CAN_STB_PIN.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
  IfxPort_setPinLow(CAN_STB_PIN.port, CAN_STB_PIN.pinIndex);

  printf("-- CAN: pins set\n");
}

static void _can_init_leds(void) {
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

  printf("-- CAN: LEDs are ready\n");
}

static void _can_accept_all_messages(void) {
  IfxCan_Filter filter;

  filter.number = 0;
  filter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxFifo0;
  filter.type = IfxCan_FilterType_range;
  filter.id1 = 0x0000;
  filter.id2 = 0xffff;

  IfxCan_Can_setStandardFilter(&can_device.sink, &filter);
  IfxCan_Can_setExtendedFilter(&can_device.sink, &filter);

  printf("-- CAN: all messages accepted\n");
}

static void _can_install_interrupts(void) {
  IfxCpu_Irq_installInterruptHandler(&can_irq_msg_sent, ISR_PRIORITY_CAN_MSG_SENT);
  IfxCpu_Irq_installInterruptHandler(&can_irq_msg_rcvd, ISR_PRIORITY_CAN_MSG_RCVD);
  IfxCpu_Irq_installInterruptHandler(&can_irq_msg_lost, ISR_PRIORITY_CAN_MSG_LOST);
  IfxCpu_Irq_installInterruptHandler(&can_irq_comm_error, ISR_PRIORITY_CAN_COMM_ERROR);
  printf("-- CAN: interrupts are set\n");
}

void can_init() {
  _can_init_device();
  _can_init_source();
  _can_init_sink();
  _can_init_pins();
  _can_init_leds();
  _can_accept_all_messages();
  _can_install_interrupts();
  printf("-- CAN: device ready\n");
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
    status = IfxCan_Can_sendMessage(&can_device.source, &header, payload);
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
  IfxCan_Can_readMessage(&can_device.sink, &header, payload);
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

