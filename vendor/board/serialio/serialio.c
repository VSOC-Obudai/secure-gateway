#include "serialio.h"

#include "Asclin/Std/IfxAsclin.h"
#include "Asclin/Asc/IfxAsclin_Asc.h"
#include "IfxCpu_Irq.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Communication parameters */
#define ISR_PRIO_UART_RX (3)   /* Priority for interrupt ISR Receive   */
#define ISR_PRIO_UART_TX (4)   /* Priority for interrupt ISR Transmit  */
#define ISR_PRIO_UART_ER (5)   /* Priority for interrupt ISR Errors    */
#define UART_RX_BUFSZ (256)    /* Define the RX buffer size in byte    */
#define UART_TX_BUFSZ (256)    /* Define the TX buffer size in byte    */
#define UART_BAUDRATE (115200) /* Define the UART baud rate            */

IfxAsclin_Asc uart_handle;
uint8_t uart_rx_buffer[UART_RX_BUFSZ + sizeof(Ifx_Fifo) + 8];
uint8_t uart_tx_buffer[UART_TX_BUFSZ + sizeof(Ifx_Fifo) + 8];

IFX_INTERRUPT(uart_rx_isr, 0, ISR_PRIO_UART_RX);

void uart_rx_isr(void)
{
  IfxAsclin_Asc_isrReceive(&uart_handle);
}

IFX_INTERRUPT(uart_tx_isr, 0, ISR_PRIO_UART_TX);

void uart_tx_isr(void)
{
  IfxAsclin_Asc_isrTransmit(&uart_handle);
}

IFX_INTERRUPT(uart_er_isr, 0, ISR_PRIO_UART_ER);

void uart_er_isr(void)
{
  IfxAsclin_Asc_isrError(&uart_handle);
}

void uart_send(char c)
{
  Ifx_SizeT count = 1;
  IfxAsclin_Asc_write(&uart_handle, &c, &count, TIME_INFINITE);
}

int uart_recv()
{
  int c;
  if (IfxAsclin_Asc_getReadCount(&uart_handle))
  {
    c = IfxAsclin_Asc_blockingRead(&uart_handle);
  }
  else
  {
    c = -1;
  }
  return c;
}

void serialio_init(void)
{
  IfxAsclin_Asc_Config ascConf;

  /* Set default configurations */
  IfxAsclin_Asc_initModuleConfig(&ascConf, &MODULE_ASCLIN0); /* Initialize the structure with default values      */

  /* Set the desired baud rate */
  ascConf.baudrate.baudrate = UART_BAUDRATE;                       /* Set the baud rate in bit/s       */
  ascConf.baudrate.oversampling = IfxAsclin_OversamplingFactor_16; /* Set the oversampling factor      */

  /* Configure the sampling mode */
  ascConf.bitTiming.medianFilter = IfxAsclin_SamplesPerBit_three;          /* Set the number of samples per bit*/
  ascConf.bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_8; /* Set the first sample position    */

  /* ISR priorities and interrupt target */
  ascConf.interrupt.txPriority = ISR_PRIO_UART_TX; /* Set the interrupt priority for TX events             */
  ascConf.interrupt.rxPriority = ISR_PRIO_UART_RX; /* Set the interrupt priority for RX events             */
  ascConf.interrupt.erPriority = ISR_PRIO_UART_ER; /* Set the interrupt priority for Error events          */
  ascConf.interrupt.typeOfService = IfxSrc_Tos_cpu0;

  /* Pin configuration */
  const IfxAsclin_Asc_Pins pins = {.cts = NULL_PTR, /* CTS pin not used                                     */
                                   .ctsMode = IfxPort_InputMode_pullUp,
                                   .rx =
                                       &IfxAsclin0_RXD_P33_10_IN, /* Select the pin for RX connected to the USB port */
                                   .rxMode = IfxPort_InputMode_pullUp, /* RX pin */
                                   .rts = NULL_PTR, /* RTS pin not used                                     */
                                   .rtsMode = IfxPort_OutputMode_pushPull,
                                   .tx = &IfxAsclin0_TX_P33_9_OUT, /* Select the pin for TX connected to the USB port */
                                   .txMode = IfxPort_OutputMode_pushPull, /* TX pin */
                                   .pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1};
  ascConf.pins = &pins;

  /* FIFO buffers configuration */
  ascConf.txBuffer = uart_tx_buffer;    /* Set the transmission buffer                          */
  ascConf.txBufferSize = UART_TX_BUFSZ; /* Set the transmission buffer size                     */
  ascConf.rxBuffer = uart_rx_buffer;    /* Set the receiving buffer                             */
  ascConf.rxBufferSize = UART_RX_BUFSZ; /* Set the receiving buffer size                        */

  /* Init ASCLIN module */
  IfxAsclin_Asc_initModule(&uart_handle, &ascConf); /* Initialize the module with the given configuration   */
}

/* POSIX read function */
/* read characters from file descriptor fd into given buffer, at most count bytes */
/* returns number of characters in buffer */
size_t read(int fd, void* buffer, size_t count)
{
  size_t index = 0;
  unsigned char* ptr = (unsigned char*)buffer;
  do
  {
    if (1 == uart_recv(ptr))
    {
      ++ptr;
      ++index;
    }
    else
    {
      /* wait at least for 1 character */
      if (index >= 1)
      {
        break;
      }
    }
  } while (index < count);
  return index;
}

/* POSIX write function */
/* write content of buffer to file descriptor fd */
/* returns number of characters that have been written */
size_t write(int fd, const void* buffer, size_t count)
{
  size_t index = 0;
  const unsigned char* ptr = (const unsigned char*)buffer;
  while (index < count)
  {
    uart_send(*ptr++);
    ++index;
  }
  return index;
}

#if defined(__TASKING__)
void _io_putc(int ch)
#else
void _putchar(int ch)
#endif
{
  if (ch == '\n')
  {
    uart_send('\n');
    uart_send('\r');
  }
  else
  {
    uart_send(ch);
  }
}
