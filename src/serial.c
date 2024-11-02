#include "serial.h"

#include <Asclin/Asc/IfxAsclin_Asc.h>
#include <Asclin/Std/IfxAsclin.h>
#include <IfxCpu_Irq.h>

#include <stdbool.h>
#include <stdint.h>

#define SERIAL_PORT (MODULE_ASCLIN0)
#define SERIAL_TX_PIN (IfxAsclin0_TX_P33_9_OUT)
#define SERIAL_RX_PIN (IfxAsclin0_RXD_P33_10_IN)

typedef struct
{
  IfxAsclin_Asc handle;
  uint8_t tx_data[SERIAL_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
  uint8_t rx_data[SERIAL_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
} serial_device_t;

serial_device_t serial_device;

IFX_INTERRUPT(isr_serial_tx_handler, 0, ISR_PRIORITY_SERIAL_TX)
{
  IfxAsclin_Asc_isrTransmit(&serial_device.handle);
}

IFX_INTERRUPT(isr_serial_rx_handler, 0, ISR_PRIORITY_SERIAL_RX)
{
  IfxAsclin_Asc_isrReceive(&serial_device.handle);
}

IFX_INTERRUPT(isr_serial_er_handler, 0, ISR_PRIORITY_SERIAL_ER)
{
  IfxAsclin_Asc_isrError(&serial_device.handle);
}

void serial_init()
{
  IfxAsclin_Asc_Config serial_cfg;

  /* Load default configuration */
  IfxAsclin_Asc_initModuleConfig(&serial_cfg, &SERIAL_PORT);

  /* Baudrate configuration */
  serial_cfg.baudrate.prescaler = 1;
  serial_cfg.baudrate.baudrate = SERIAL_BAUDRATE;
  serial_cfg.baudrate.oversampling = IfxAsclin_OversamplingFactor_16;

  /* Sampling mode configuration */
  serial_cfg.bitTiming.medianFilter = IfxAsclin_SamplesPerBit_three;
  serial_cfg.bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_8;

  /* Interrupts configuration */
  serial_cfg.interrupt.txPriority = ISR_PRIORITY_SERIAL_TX;
  serial_cfg.interrupt.rxPriority = ISR_PRIORITY_SERIAL_RX;
  serial_cfg.interrupt.erPriority = ISR_PRIORITY_SERIAL_ER;
  serial_cfg.interrupt.typeOfService = IfxSrc_Tos_cpu0;

  /* FIFO configuration */
  serial_cfg.txBuffer = serial_device.tx_data;
  serial_cfg.txBufferSize = SERIAL_TX_BUFFER_SIZE;
  serial_cfg.rxBuffer = serial_device.rx_data;
  serial_cfg.rxBufferSize = SERIAL_RX_BUFFER_SIZE;

  /* Pins configuration */
  IfxAsclin_Asc_Pins pins = {.cts = NULL,
                             .ctsMode = IfxPort_InputMode_pullUp,
                             .rts = NULL,
                             .rtsMode = IfxPort_OutputMode_pushPull,
                             .rx = &SERIAL_RX_PIN,
                             .rxMode = IfxPort_InputMode_pullUp,
                             .tx = &SERIAL_TX_PIN,
                             .txMode = IfxPort_OutputMode_pushPull,
                             .pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1};
  serial_cfg.pins = &pins;

  /* Initialize Serial I/O module */
  IfxAsclin_Asc_initModule(&serial_device.handle, &serial_cfg);
}

int serial_recv(void)
{
  return IfxAsclin_Asc_blockingRead(&serial_device.handle);
}

void serial_send(int ch)
{
  IfxAsclin_Asc_blockingWrite(&serial_device.handle, ch);
}
