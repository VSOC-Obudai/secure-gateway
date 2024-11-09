#include "can.h"
#include "isr_config.h"
#include "led.h"

#include <Can/Can/IfxCan_Can.h>
#include <Can/Std/IfxCan.h>
#include <IfxCpu_Irq.h>
#include <IfxPort_PinMap.h>
#include <SysSe/Bsp/Bsp.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>

static const IfxCan_Can_Pins default_can_pins = {
    .padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed2,
    .txPin = &CAN00_TX_PIN,
    .txPinMode = IfxPort_OutputMode_pushPull,
    .rxPin = &CAN00_RX_PIN,
    .rxPinMode = IfxPort_InputMode_pullUp};

typedef struct {
  IfxCan_Can handle;
  IfxCan_Can_Node tx_node_handle;
  IfxCan_Can_Node rx_node_handle;
  IfxCan_Message tx_header;
  IfxCan_Message rx_header;
  uint32 tx_payload[2];
  uint32 rx_payload[2];
} can_device_t;

can_device_t can_device;

IFX_INTERRUPT(can_isr_tx_buffer_handler, 1, ISR_PRIORITY_CAN_TX_BUFFER) {
  IfxCan_Node_clearInterruptFlag(can_device.tx_node_handle.node,
                                 IfxCan_Interrupt_transmissionCompleted);
  led_toggle(&led_0);
  //printf("!! INTERRUPT[TX] !!\n");
}

IFX_INTERRUPT(can_isr_rx_buffer_handler, 0, ISR_PRIORITY_CAN_RX_BUFFER) {
  can_frame_t received_frame;
  can_recv(&received_frame);
  led_toggle(&led_1);
  // printf("!! INTERRUPT[RX] !!\n");
  IfxCan_Node_clearInterruptFlag(
      can_device.rx_node_handle.node,
      IfxCan_Interrupt_messageStoredToDedicatedRxBuffer);
}

void __can_init_device(void) {
  IfxCan_Can_Config config;
  printf("-- __can_init_device started\n");
  IfxCan_Can_initModuleConfig(&config, &CAN0_PORT);
  IfxCan_Can_initModule(&can_device.handle, &config);
  printf("-- __can_init_device done\n");
}

void __can_init_tx_pin(void) {
  IfxCan_Can_NodeConfig can_node_config;

  printf("-- __can_init_tx_pin started\n");

  IfxCan_Can_initNodeConfig(&can_node_config, &can_device.handle);

  //can_node_config.busLoopbackEnabled = TRUE;

  can_node_config.nodeId = IfxCan_NodeId_1;
  can_node_config.frame.type = IfxCan_FrameType_transmit;

  can_node_config.interruptConfig.transmissionCompletedEnabled = TRUE;
  can_node_config.interruptConfig.traco.priority = ISR_PRIORITY_CAN_TX_BUFFER;
  can_node_config.interruptConfig.traco.interruptLine = IfxCan_InterruptLine_1;
  can_node_config.interruptConfig.traco.typeOfService = IfxSrc_Tos_cpu0;

  can_node_config.pins = &default_can_pins;

  IfxCan_Can_initNode(&can_device.tx_node_handle, &can_node_config);

  printf("-- __can_init_tx_pin done\n");
}

void __can_init_rx_pin(void) {
  IfxCan_Can_NodeConfig can_node_config;

  printf("-- __can_init_rx_pin started\n");

  IfxCan_Can_initNodeConfig(&can_node_config, &can_device.handle);

  //can_node_config.busLoopbackEnabled = TRUE;

  can_node_config.nodeId = IfxCan_NodeId_0;
  can_node_config.frame.type = IfxCan_FrameType_receive;

  can_node_config.interruptConfig.messageStoredToDedicatedRxBufferEnabled =
      TRUE;
  can_node_config.interruptConfig.reint.priority = ISR_PRIORITY_CAN_RX_BUFFER;
  can_node_config.interruptConfig.reint.interruptLine = IfxCan_InterruptLine_0;
  can_node_config.interruptConfig.reint.typeOfService = IfxSrc_Tos_cpu0;

  can_node_config.pins = &default_can_pins;

  IfxCan_Can_initNode(&can_device.rx_node_handle, &can_node_config);

  printf("-- __can_init_rx_pin done\n");
}

void __can_init_pins(void) {
  printf("-- __can_init_pins started\n");

  IfxPort_setPinModeOutput(CAN00_TX_PIN.pin.port, CAN00_TX_PIN.pin.pinIndex,
                           IfxPort_OutputMode_pushPull,
                           IfxPort_OutputIdx_general);
  IfxPort_setPinLow(CAN00_TX_PIN.pin.port, CAN00_TX_PIN.pin.pinIndex);

  IfxPort_setPinModeOutput(CAN00_RX_PIN.pin.port, CAN00_RX_PIN.pin.pinIndex,
                           IfxPort_OutputMode_pushPull,
                           IfxPort_OutputIdx_general);
  IfxPort_setPinLow(CAN00_RX_PIN.pin.port, CAN00_RX_PIN.pin.pinIndex);

  IfxPort_setPinModeOutput(CAN_STB_PIN.port, CAN_STB_PIN.pinIndex,
                           IfxPort_OutputMode_pushPull,
                           IfxPort_OutputIdx_general);
  IfxPort_setPinLow(CAN_STB_PIN.port, CAN_STB_PIN.pinIndex);

  printf("-- __can_init_pins done\n");
}

void __can_install_interrupts(void) {
  // printf("-- __can_install_interrupts started\n");
  // IfxCpu_Irq_installInterruptHandler(&can_isr_tx_buffer_handler,
  //                                    ISR_PRIORITY_CAN_TX_BUFFER);
  // IfxCpu_Irq_installInterruptHandler(&can_isr_rx_buffer_handler,
  //                                    ISR_PRIORITY_CAN_RX_BUFFER);
  // printf("-- __can_install_interrupts done\n");
}

void __can_accept_all_messages() {
  IfxCan_Filter filter;

  printf("-- __can_accept_all_messages started\n");

  filter.number = 0;
  filter.rxBufferOffset = IfxCan_RxBufferId_0;
  filter.elementConfiguration =
      IfxCan_FilterElementConfiguration_storeInRxBuffer;
  filter.type = IfxCan_FilterType_range;
  filter.id1 = 0x00000000;
  filter.id2 = 0xffffffff;

  IfxCan_Can_setStandardFilter(&can_device.rx_node_handle, &filter);
  IfxCan_Can_setExtendedFilter(&can_device.rx_node_handle, &filter);

  while (TRUE != IfxCan_Can_isNodeSynchronized(&can_device.rx_node_handle))
    ;

  IfxCan_Can_setStandardFilter(&can_device.tx_node_handle, &filter);
  IfxCan_Can_setExtendedFilter(&can_device.tx_node_handle, &filter);

  while (TRUE != IfxCan_Can_isNodeSynchronized(&can_device.tx_node_handle))
    ;

  printf("-- __can_accept_all_messages done\n");
}

void __can_init_leds(void) {
  printf("-- __can_init_leds started\n");

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

  printf("-- __can_init_leds done\n");
}

void __can_print_message(const char *const prefix,
                         const can_frame_t *const frame) {
  printf("{ direction: \"%2s\", can_id: %lX, length: %02d, data:", prefix,
         frame->can_id, frame->len);
  for (uint32_t i = 0; i < frame->len; ++i) {
    printf(" 0x%02X", frame->data[i]);
  }
  printf(" }\n");
}

void can_init() {
  printf("-- can_init started\n");

  __can_init_device();
  __can_init_tx_pin();
  __can_init_rx_pin();
  __can_init_pins();
  __can_init_leds();
  __can_accept_all_messages();
  //__can_install_interrupts();

  printf("-- can_init done\n");
}

void can_send(const can_frame_t *const frame) {
  IfxCan_Status status = IfxCan_Status_ok;

  // printf("-- can_send started\n");

  can_device.tx_header.messageId = frame->can_id;
  can_device.tx_header.dataLengthCode =
      IfxCan_Node_getCodeFromDataLengthInBytes(frame->len);
  can_device.tx_payload[0] = frame->data[0];
  can_device.tx_payload[0] |= frame->data[1] << 8;
  can_device.tx_payload[0] |= frame->data[2] << 16;
  can_device.tx_payload[0] |= frame->data[3] << 24;
  can_device.tx_payload[1] = frame->data[4];
  can_device.tx_payload[1] |= frame->data[5] << 8;
  can_device.tx_payload[1] |= frame->data[6] << 16;
  can_device.tx_payload[1] |= frame->data[7] << 24;

  do {
    status = IfxCan_Can_sendMessage(&can_device.tx_node_handle,
                                    &can_device.tx_header,
                                    &can_device.tx_payload[0]);
  } while (status == IfxCan_Status_notSentBusy);

  __can_print_message("TX", frame);

  // printf("-- can_send done\n");
}

void can_recv(can_frame_t *frame) {
  // printf("-- can_recv started\n");
  IfxCan_Can_initMessage(&can_device.rx_header);
  IfxCan_Can_readMessage(&can_device.rx_node_handle, &can_device.rx_header,
                         &can_device.rx_payload[0]);

  frame->can_id = can_device.rx_header.messageId;
  frame->len =
      IfxCan_Node_getDataLengthInBytes(can_device.rx_header.dataLengthCode);
  frame->data[0] = (uint8_t)(can_device.rx_payload[0]);
  frame->data[1] = (uint8_t)(can_device.rx_payload[0] >> 8);
  frame->data[2] = (uint8_t)(can_device.rx_payload[0] >> 16);
  frame->data[3] = (uint8_t)(can_device.rx_payload[0] >> 24);
  frame->data[4] = (uint8_t)(can_device.rx_payload[1]);
  frame->data[5] = (uint8_t)(can_device.rx_payload[1] >> 8);
  frame->data[6] = (uint8_t)(can_device.rx_payload[1] >> 16);
  frame->data[7] = (uint8_t)(can_device.rx_payload[1] >> 24);

  __can_print_message("RX", frame);

  // printf("-- can_recv done\n");
}
