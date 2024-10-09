#include "can/can.h"

#include "IfxCan.h"
#include "IfxCan_Can.h"

#include <stdio.h>
#include <string.h>

#define CAN_BUS_COUNT (12)
#define CAN_MSG_PAYLOAD_SIZE (2) /* CAN */
// #define CAN_MSG_PAYLOAD_SIZE (16) /* CAN FD */

typedef struct
{
  Ifx_CAN* addr;
  IfxCan_Can_Pins pins;
  IfxCan_Can_Config config;
  IfxCan_Can_NodeConfig node_config;
} can_device_config_t;

static const can_device_config_t can_device_config[CAN_BUS_COUNT] = {
    {.addr = &MODULE_CAN0,
     .pins = {&IfxCan_TXD00_P02_0_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD00A_P02_1_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN0,
     .pins = {&IfxCan_TXD01_P01_3_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD01C_P01_4_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN0,
     .pins = {&IfxCan_TXD02_P02_2_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD02B_P02_3_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN0,
     .pins = {&IfxCan_TXD03_P00_2_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD03A_P00_3_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN1,
     .pins = {&IfxCan_TXD10_P00_0_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD10A_P00_1_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN1,
     .pins = {&IfxCan_TXD11_P00_4_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD11B_P00_5_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN1,
     .pins = {&IfxCan_TXD12_P10_7_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD12B_P10_8_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN1,
     .pins = {&IfxCan_TXD13_P33_4_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD13B_P33_5_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN2,
     .pins = {&IfxCan_TXD20_P34_1_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD20C_P34_2_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN2,
     .pins = {&IfxCan_TXD21_P20_3_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD21D_P32_2_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN2,
     .pins = {&IfxCan_TXD22_P33_12_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD22A_P33_13_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}},
    {.addr = &MODULE_CAN2,
     .pins = {&IfxCan_TXD23_P14_9_OUT, IfxPort_OutputMode_pushPull, &IfxCan_RXD23A_P14_10_IN,
              IfxPort_InputMode_noPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed4}}};

typedef struct
{
  IfxCan_Can handle;
  IfxCan_Can_Node node;
  IfxCan_Filter filter;
  IfxCan_Message tx_msg;
  IfxCan_Message rx_msg;
  uint32_t tx_data[CAN_MSG_PAYLOAD_SIZE];
  uint32_t rx_data[CAN_MSG_PAYLOAD_SIZE];
  char name[16];
} can_device_t;

static can_device_t can_device_list[CAN_BUS_COUNT] = {{.name = "can-0.0"}, {.name = "can-0.1"}, {.name = "can-0.2"},
                                                      {.name = "can-0.3"}, {.name = "can-1.0"}, {.name = "can-1.1"},
                                                      {.name = "can-1.2"}, {.name = "can-1.3"}, {.name = "can-2.0"},
                                                      {.name = "can-2.1"}, {.name = "can-2.2"}, {.name = "can-2.3"}};

IfxCan_Filter mcmcan_std_default_filter = {.number = 0,
                                           .elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxFifo0,
                                           .type = IfxCan_FilterType_classic,
                                           .id1 = 0,
                                           .id2 = 0,
                                           .rxBufferOffset = IfxCan_RxBufferId_0};

void can_init_node(IfxCan_Can_NodeConfig* config, IfxCan_Can* can)
{
  static IfxCan_Can_NodeConfig defaultConfig =
      {.can = NULL_PTR,
       .nodeId = IfxCan_NodeId_0,
       .clockSource = IfxCan_ClockSource_both,
       .frame = {.type = IfxCan_FrameType_transmitAndReceive, .mode = IfxCan_FrameMode_fdLongAndFast},
       .baudRate = {.baudrate = 500000,
                    .samplePoint = 8000,
                    .syncJumpWidth = 2000,
                    .prescaler = 0,
                    .timeSegment1 = 3,
                    .timeSegment2 = 10},
       .fastBaudRate = {.baudrate = 2000000,
                        .samplePoint = 8000,
                        .syncJumpWidth = 2000,
                        .prescaler = 1,
                        .timeSegment1 = 3,
                        .timeSegment2 = 10,
                        .tranceiverDelayOffset = 28},
       .txConfig = {.txMode = IfxCan_TxMode_fifo,
                    .dedicatedTxBuffersNumber = 0,
                    .txFifoQueueSize = 32,
                    .txBufferDataFieldSize = IfxCan_DataFieldSize_64,
                    .txEventFifoSize = 0},
       .filterConfig = {.messageIdLength = IfxCan_MessageIdLength_both,
                        .standardListSize = 64,
                        .extendedListSize = 32,
                        .rejectRemoteFramesWithStandardId = TRUE,
                        .rejectRemoteFramesWithExtendedId = TRUE,
                        .standardFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_reject,
                        .extendedFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_reject},
       .rxConfig = {.rxMode = IfxCan_RxMode_fifo0,
                    .rxBufferDataFieldSize = IfxCan_DataFieldSize_64,
                    .rxFifo0DataFieldSize = IfxCan_DataFieldSize_64,
                    .rxFifo1DataFieldSize = IfxCan_DataFieldSize_64,
                    .rxFifo0OperatingMode = IfxCan_RxFifoMode_overwrite,
                    .rxFifo1OperatingMode = IfxCan_RxFifoMode_overwrite,
                    .rxFifo0WatermarkLevel = 0,
                    .rxFifo1WatermarkLevel = 0,
                    .rxFifo0Size = 16,
                    .rxFifo1Size = 0},
       .messageRAM = {.baseAddress = (uint32)&MODULE_CAN0,
                      .standardFilterListStartAddress = 0x0,
                      .extendedFilterListStartAddress = 0x100,
                      .rxFifo0StartAddress = 0x200,
                      .rxFifo1StartAddress = 0x0,
                      .rxBuffersStartAddress = 0x0,
                      .txEventFifoStartAddress = 0x0,
                      .txBuffersStartAddress = 0x700},
       .interruptConfig =
           {.rxFifo0NewMessageEnabled = TRUE,
            .rxFifo0WatermarkEnabled = FALSE,
            .rxFifo0FullEnabled = FALSE,
            .rxFifo0MessageLostEnabled = FALSE,
            .rxFifo1NewMessageEnabled = FALSE,
            .rxFifo1WatermarkEnabled = FALSE,
            .rxFifo1FullEnabled = FALSE,
            .rxFifo1MessageLostEnabled = FALSE,
            .highPriorityMessageEnabled = FALSE,
            .transmissionCompletedEnabled = FALSE,
            .transmissionCancellationFinishedEnabled = FALSE,
            .txFifoEmptyEnabled = FALSE,
            .txEventFifoNewEntryEnabled = FALSE,
            .txEventFifoWatermarkEnabled = FALSE,
            .txEventFifoFullEnabled = FALSE,
            .txEventFifoEventLostEnabled = FALSE,
            .timestampWraparoundEnabled = FALSE,
            .messageRAMAccessFailureEnabled = FALSE,
            .timeoutOccurredEnabled = FALSE,
            .messageStoredToDedicatedRxBufferEnabled = FALSE,
            .errorLoggingOverflowEnabled = FALSE,
            .errorPassiveEnabled = FALSE,
            .warningStatusEnabled = FALSE,
            .busOffStatusEnabled = TRUE,
            .watchdogEnabled = FALSE,
            .protocolErrorArbitrationEnabled = FALSE,
            .protocolErrorDataEnabled = FALSE,
            .tefifo = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .hpe = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .wati = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .alrt = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .moer = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .safe = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .boff = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .loi = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .reint = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .rxf1f = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .rxf0f = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .rxf1n = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .rxf0n = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .reti = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .traq = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0},
            .traco = {.interruptLine = IfxCan_InterruptLine_0, .priority = 0, .typeOfService = IfxSrc_Tos_cpu0}},
       .pins = NULL_PTR,
       .busLoopbackEnabled = FALSE,
       .calculateBitTimingValues = TRUE};

  /* Default Configuration */
  *config = defaultConfig;

  /* take over module pointer */
  config->can = can->can;
}

static void can_accept_all_messages(void)
{
  for (uint8 i = 0; i < CAN_BUS_COUNT; ++i)
  {
    can_device_list[i].filter.number = 0;
    can_device_list[i].filter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxFifo0;
    can_device_list[i].filter.type = IfxCan_FilterType_classic;
    // for testing
    can_device_list[i].filter.id1 = 0x7B;
    can_device_list[i].filter.id2 = 0xFFFFFFFF;
    IfxCan_Can_setStandardFilter(&can_device_list[i].node, &can_device_list[i].filter);
  }
}

uint8_t can_init(void)
{
  IfxCan_Can_Config canConfig;
  IfxCan_Can_NodeConfig canNodeConfig;
  for (uint8_t i = 0; i < CAN_BUS_COUNT; i++)
  {
    IfxCan_Can_initModuleConfig(&canConfig, can_device_config[i].addr);
    IfxCan_Can_initModule(&can_device_list[i].handle, &canConfig);

    can_init_node(&canNodeConfig, &can_device_list[i].handle);

    canNodeConfig.nodeId = IfxCan_NodeId_0 + i % 4;

    canNodeConfig.messageRAM.baseAddress = (uint32)can_device_config[i].addr;
    canNodeConfig.messageRAM.standardFilterListStartAddress = 0x0 + 0x1000 * (i % 4);
    canNodeConfig.messageRAM.extendedFilterListStartAddress = 0x100 + 0x1000 * (i % 4);
    canNodeConfig.messageRAM.rxFifo0StartAddress = 0x200 + 0x1000 * (i % 4);
    canNodeConfig.messageRAM.txBuffersStartAddress = 0x700 + 0x1000 * (i % 4);

    canNodeConfig.filterConfig.messageIdLength = IfxCan_MessageIdLength_both;
    canNodeConfig.filterConfig.standardListSize = 0;
    canNodeConfig.filterConfig.extendedListSize = 0;
    canNodeConfig.filterConfig.standardFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_acceptToRxFifo0;
    canNodeConfig.filterConfig.extendedFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_acceptToRxFifo0;
    canNodeConfig.filterConfig.rejectRemoteFramesWithStandardId = TRUE;
    canNodeConfig.filterConfig.rejectRemoteFramesWithExtendedId = TRUE;

    canNodeConfig.interruptConfig.traco.priority = 110 + i;
    canNodeConfig.interruptConfig.traco.interruptLine = IfxCan_InterruptLine_0 + i % 4;
    canNodeConfig.interruptConfig.traco.typeOfService = IfxSrc_Tos_cpu0;
    canNodeConfig.interruptConfig.rxf0n.priority = 130 + i;
    canNodeConfig.interruptConfig.rxf0n.interruptLine = IfxCan_InterruptLine_4 + i % 4;
    canNodeConfig.interruptConfig.rxf0n.typeOfService = IfxSrc_Tos_cpu0;
    canNodeConfig.interruptConfig.boff.priority = 150 + i;
    canNodeConfig.interruptConfig.boff.interruptLine = IfxCan_InterruptLine_8 + i % 4;
    canNodeConfig.interruptConfig.boff.typeOfService = IfxSrc_Tos_cpu0;

    canNodeConfig.pins = &can_device_config[i].pins;

    IfxCan_Can_initNode(&can_device_list[i].node, &canNodeConfig);

    IfxCan_Can_initMessage(&can_device_list[i].rx_msg);
    can_device_list[i].rx_msg.readFromRxFifo0 = TRUE;

    printf("CAN bus %s initialized successfully!\n", can_device_list[i].name);
  }

  can_accept_all_messages();

  printf("All CAN node is initialized successfully!\n");
  return 0;
}

void _print_can_message(const char* prefix, uint32 msg_id, uint32 length, uint8* msg)
{
  printf("[%s] | id: 0x%lX | length: %ud | data:", prefix, msg_id, length);
  for (int i = 0; i < length; ++i)
  {
    printf(" %02X ", msg[i]);
  }
  printf("\n");
}

#define ISR_RX_HANDLER(isr_name, vector_tab, priority, can_dev)                                                        \
  IFX_INTERRUPT(isr_name, vector_tab, priority);                                                                       \
  void isr_name(void)                                                                                                  \
  {                                                                                                                    \
    IfxCan_Node_clearInterruptFlag(can_dev.node.node, IfxCan_Interrupt_rxFifo0NewMessage);                             \
    IfxCan_Can_readMessage(&can_dev.node, &can_dev.rx_msg, can_dev.rx_data);                                           \
    _print_can_message("RX", can_dev.rx_msg.messageId, can_dev.rx_msg.dataLengthCode, &can_dev.rx_data[0]);            \
  }

ISR_RX_HANDLER(can00_rx_isr, 0, 130, can_device_list[0]);
ISR_RX_HANDLER(can01_rx_isr, 0, 131, can_device_list[1]);
ISR_RX_HANDLER(can02_rx_isr, 0, 132, can_device_list[2]);
ISR_RX_HANDLER(can03_rx_isr, 0, 133, can_device_list[3]);
ISR_RX_HANDLER(can10_rx_isr, 0, 134, can_device_list[4]);
ISR_RX_HANDLER(can11_rx_isr, 0, 135, can_device_list[5]);
ISR_RX_HANDLER(can12_rx_isr, 0, 136, can_device_list[6]);
ISR_RX_HANDLER(can13_rx_isr, 0, 137, can_device_list[7]);
ISR_RX_HANDLER(can20_rx_isr, 0, 138, can_device_list[8]);
ISR_RX_HANDLER(can21_rx_isr, 0, 139, can_device_list[9]);
ISR_RX_HANDLER(can22_rx_isr, 0, 140, can_device_list[10]);
ISR_RX_HANDLER(can23_rx_isr, 0, 141, can_device_list[11]);
