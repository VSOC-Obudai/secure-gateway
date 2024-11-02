#include "can.h"
#include "assert.h"
#include "led.h"

#include <Can/Can/IfxCan_Can.h>
#include <Can/Std/IfxCan.h>
#include <IfxCpu_Irq.h>
#include <IfxPort_PinMap.h>

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define CAN_PORT (MODULE_CAN0)
#define CAN_TX_PIN (IfxCan_TXD00_P02_0_OUT)
#define CAN_RX_PIN (IfxCan_RXD00A_P02_1_IN)
#define CAN_STB (IfxPort_P33_0)

typedef struct
{
  IfxCan_Can handle;
  IfxCan_Can_Node node;
  IfxCan_Filter filter;
  IfxCan_Message tx_msg;
  IfxCan_Message rx_msg;
  uint32_t tx_data[CAN_RX_PAYLOAD_SIZE];
  uint32_t rx_data[CAN_RX_PAYLOAD_SIZE];
} can_device_t;

can_device_t can_device;

void can_print_message(const char* prefix, uint32_t msg_id, uint8_t* data, uint32_t size)
{
  printf("{ type: \"%s\", id: %uX, size: %ud, data: %02X %02X %02X %02X %02X %02X %02X %02X }\n", prefix, msg_id, size,
         data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
}

IFX_INTERRUPT(isr_can_tx_handler, 0, ISR_PRIORITY_CAN_TX)
{
  //can_frame_t frame;
  IfxCan_Node_clearInterruptFlag(can_device.node.node, IfxCan_Interrupt_transmissionCompleted);
  //can_send(&frame);
  led_toggle(&led_0);
}

IFX_INTERRUPT(isr_can_rx_handler, 0, ISR_PRIORITY_CAN_RX)
{
  can_frame_t frame;
  IfxCan_Node_clearInterruptFlag(can_device.node.node, IfxCan_Interrupt_messageStoredToDedicatedRxBuffer);
  IfxCan_Node_clearRxBufferNewDataFlag(can_device.node.node, can_device.filter.rxBufferOffset);
  led_toggle(&led_1);
  can_recv(&frame);
}

void can_reset(void)
{
  IfxCan_Can_Config config;
  IfxCan_Can_initModuleConfig(&config, &CAN_PORT);
  IfxCan_Can_initModule(&can_device.handle, &config);
}

void can_reset_node(void)
{
  IfxCan_Can_NodeConfig config;
  IfxCan_Can_initNodeConfig(&config, &can_device.handle);

  /* General node configurations */
  config.busLoopbackEnabled = FALSE;
  config.nodeId = IfxCan_NodeId_0;
  config.clockSource = IfxCan_ClockSource_both;
  config.baudRate.baudrate = CAN_BAUDRATE;
  config.frame.type = IfxCan_FrameType_transmitAndReceive;
  config.frame.mode = IfxCan_FrameMode_fdLongAndFast;

  /* TX configrations */
  config.txConfig.txMode = IfxCan_TxMode_dedicatedBuffers;
  config.txConfig.dedicatedTxBuffersNumber = 30;
  config.txConfig.txBufferDataFieldSize = IfxCan_DataFieldSize_8;

  /* RX configurations */
  config.rxConfig.rxMode = IfxCan_RxMode_dedicatedBuffers;
  config.rxConfig.rxBufferDataFieldSize = IfxCan_DataFieldSize_8;

  /* Interrupts configuration */
  config.interruptConfig.messageStoredToDedicatedRxBufferEnabled = TRUE; /* RX interrupts */
  config.interruptConfig.reint.priority = ISR_PRIORITY_CAN_RX;
  config.interruptConfig.reint.interruptLine = IfxCan_InterruptLine_1;
  config.interruptConfig.reint.typeOfService = IfxSrc_Tos_cpu0;
  config.interruptConfig.transmissionCompletedEnabled = TRUE; /* TX interrupts */
  config.interruptConfig.traco.priority = ISR_PRIORITY_CAN_TX;
  config.interruptConfig.traco.interruptLine = IfxCan_InterruptLine_0;
  config.interruptConfig.traco.typeOfService = IfxSrc_Tos_cpu0;

  /* Filter configuration */
  config.filterConfig.messageIdLength = IfxCan_MessageIdLength_standard;
  config.filterConfig.standardListSize = 1;

  /* Pins configuration */
  IfxCan_Can_Pins can_pins = {.txPin = &CAN_TX_PIN,
                              .txPinMode = IfxPort_OutputMode_pushPull,
                              .rxPin = &CAN_RX_PIN,
                              .rxPinMode = IfxPort_InputMode_pullUp,
                              .padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed2};
  config.pins = &can_pins;

  IfxCan_Can_initNode(&can_device.node, &config);
}

void can_reset_stb_pin(void)
{
  IfxPort_setPinLow(CAN_STB.port, CAN_STB.pinIndex);
  IfxPort_setPinModeOutput(CAN_STB.port, CAN_STB.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
}

void can_accept_all_messages(void)
{
  can_device.filter.number = 0;
  can_device.filter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxBuffer;
  can_device.filter.rxBufferOffset = IfxCan_RxBufferId_0;
  can_device.filter.type = IfxCan_FilterType_range;
  can_device.filter.id1 = 0x00000000;
  can_device.filter.id2 = 0xffffffff;
  IfxCan_Can_setStandardFilter(&can_device.node, &can_device.filter);
}

void can_init()
{
  can_reset();
  can_reset_node();
  can_reset_stb_pin();
  can_accept_all_messages();
  led_init(&led_0);
  led_init(&led_1);
}

void can_send(const can_frame_t* const frame)
{
  M_ASSERT(frame != NULL);
  IfxCan_Can_initMessage(&can_device.tx_msg);
  can_device.tx_msg.messageId = frame->id;
  can_device.tx_msg.messageIdLength = IfxCan_MessageIdLength_both;
  can_device.tx_msg.dataLengthCode = frame->size;
  can_device.tx_data[0] = frame->data[0];
  can_device.tx_data[0] |= frame->data[1] << 8;
  can_device.tx_data[0] |= frame->data[2] << 16;
  can_device.tx_data[0] |= frame->data[3] << 24;
  can_device.tx_data[1] = frame->data[4];
  can_device.tx_data[1] |= frame->data[5] << 8;
  can_device.tx_data[1] |= frame->data[6] << 16;
  can_device.tx_data[1] |= frame->data[7] << 24;
  while (IfxCan_Status_notSentBusy == IfxCan_Can_sendMessage(&can_device.node, &can_device.tx_msg, can_device.tx_data))
  {
  }
  can_print_message("TX", frame->id, frame->data, frame->size);
}

void can_recv(can_frame_t* frame)
{
  M_ASSERT(frame != NULL);
  IfxCan_Can_initMessage(&can_device.rx_msg);
  IfxCan_Can_readMessage(&can_device.node, &can_device.rx_msg, can_device.rx_data);
  frame->id = can_device.rx_msg.messageId;
  frame->size = can_device.rx_msg.dataLengthCode;
  frame->data[0] = (uint8_t)can_device.rx_data[0];
  frame->data[1] = (uint8_t)(can_device.rx_data[0] >> 8);
  frame->data[2] = (uint8_t)(can_device.rx_data[0] >> 16);
  frame->data[3] = (uint8_t)(can_device.rx_data[0] >> 24);
  frame->data[4] = (uint8_t)can_device.rx_data[1];
  frame->data[5] = (uint8_t)(can_device.rx_data[1] >> 8);
  frame->data[6] = (uint8_t)(can_device.rx_data[1] >> 16);
  frame->data[7] = (uint8_t)(can_device.rx_data[1] >> 24);
  can_print_message("RX", frame->id, frame->data, frame->size);
}
