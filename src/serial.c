#include "serial.h"
#include "isr_config.h"

#include "SysSe/Bsp/Bsp.h"

#include <Asclin/Asc/IfxAsclin_Asc.h>
#include <Asclin/Std/IfxAsclin.h>

#include <IfxCpu_Irq.h>

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define SERIAL_BAUDRATE (115200)

#define SERIAL_PORT (MODULE_ASCLIN0)
#define SERIAL_TX_PIN (IfxAsclin0_TX_P33_9_OUT)
#define SERIAL_RX_PIN (IfxAsclin0_RXD_P33_10_IN)

#define SERIAL_TX_BUFFER_SIZE (64)
#define SERIAL_RX_BUFFER_SIZE (64)

typedef struct
{
  IfxAsclin_Asc handle;
  uint8_t tx_data[SERIAL_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
  uint8_t rx_data[SERIAL_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
} serial_device_t;

serial_device_t serial_device;

IFX_INTERRUPT(serial_isr_transmit_handler, 0, ISR_PRIORITY_SERIAL_TX)
{
  IfxAsclin_Asc_isrTransmit(&serial_device.handle);
}

IFX_INTERRUPT(serial_isr_receive_handler, 0, ISR_PRIORITY_SERIAL_RX)
{
  IfxAsclin_Asc_isrReceive(&serial_device.handle);
}

IFX_INTERRUPT(serial_isr_error_handler, 0, ISR_PRIORITY_SERIAL_ER)
{
  IfxAsclin_Asc_isrError(&serial_device.handle);
}

void __serial_init_device(void)
{
  IfxAsclin_Asc_Config config = {};
  IfxAsclin_Asc_Pins pins = {};

  /* Load default configuration */
  IfxAsclin_Asc_initModuleConfig(&config, &SERIAL_PORT);

  /* Baudrate configuration */
  config.baudrate.prescaler = 1;
  config.baudrate.baudrate = SERIAL_BAUDRATE;
  config.baudrate.oversampling = IfxAsclin_OversamplingFactor_16;

  /* Sampling mode configuration */
  config.bitTiming.medianFilter = IfxAsclin_SamplesPerBit_three;
  config.bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_8;

  /* Interrupts configuration */
  config.interrupt.txPriority = ISR_PRIORITY_SERIAL_TX;
  config.interrupt.rxPriority = ISR_PRIORITY_SERIAL_RX;
  config.interrupt.erPriority = ISR_PRIORITY_SERIAL_ER;
  config.interrupt.typeOfService = IfxSrc_Tos_cpu0;

  /* FIFO configuration */
  config.txBuffer = serial_device.tx_data;
  config.txBufferSize = SERIAL_TX_BUFFER_SIZE;
  config.rxBuffer = serial_device.rx_data;
  config.rxBufferSize = SERIAL_RX_BUFFER_SIZE;

  /* Pins configuration */
  pins.pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;
  pins.tx = &SERIAL_TX_PIN;
  pins.txMode = IfxPort_OutputMode_pushPull;
  pins.rx = &SERIAL_RX_PIN;
  pins.rxMode = IfxPort_InputMode_pullUp;
  config.pins = &pins;

  /* Initialize Serial I/O module */
  IfxAsclin_Asc_initModule(&serial_device.handle, &config);
}

void __serial_install_interrupts(void)
{
  //IfxCpu_Irq_installInterruptHandler(&serial_isr_transmit_handler, ISR_PRIORITY_SERIAL_TX);
  //IfxCpu_Irq_installInterruptHandler(&serial_isr_receive_handler, ISR_PRIORITY_SERIAL_RX);
  //IfxCpu_Irq_installInterruptHandler(&serial_isr_error_handler, ISR_PRIORITY_SERIAL_ER);
  //enableInterrupts();
}

void serial_init()
{
  __serial_init_device();
  //__serial_install_interrupts();
}

int serial_getc()
{
  int c;
  if (IfxAsclin_Asc_getReadCount(&serial_device.handle))
  {
    c = IfxAsclin_Asc_blockingRead(&serial_device.handle);
  }
  else
  {
    c = -1;
  }
  return c;
}

int serial_putc(uint8_t c)
{
  volatile Ifx_ASCLIN_TXDATA* tx_data = (Ifx_ASCLIN_TXDATA*)&serial_device.handle.asclin->TXDATA.U;
  tx_data->U = c;

  volatile Ifx_ASCLIN_FLAGS* tx_flag = (Ifx_ASCLIN_FLAGS*)&serial_device.handle.asclin->FLAGS;
  while(tx_flag->B.TC == FALSE);

  Ifx_ASCLIN_FLAGSCLEAR* tc_flag = (Ifx_ASCLIN_FLAGSCLEAR*)&serial_device.handle.asclin->FLAGSCLEAR;
  tc_flag->B.TCC = 1;

  return 1;
}
