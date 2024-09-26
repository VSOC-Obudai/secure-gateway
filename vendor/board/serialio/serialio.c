#include "serialio.h"

#include "IfxCpu_Irq.h"
#include "ifxAsclin_Asc.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Communication parameters */
#define ISR_PRIORITY_ASCLIN_TX 8  /* Priority for interrupt ISR Transmit  */
#define ISR_PRIORITY_ASCLIN_RX 4  /* Priority for interrupt ISR Receive   */
#define ISR_PRIORITY_ASCLIN_ER 12 /* Priority for interrupt ISR Errors    */
#define ASC_TX_BUFFER_SIZE 256    /* Define the TX buffer size in byte    */
#define ASC_RX_BUFFER_SIZE 256    /* Define the RX buffer size in byte    */
#define ASC_BAUDRATE 115200       /* Define the UART baud rate            */

static IfxAsclin_Asc asclin; /* ASCLIN module object                 */
uint8_t TC_UartTxBuffer[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
uint8_t TC_UartRxBuffer[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];

IFX_INTERRUPT(asclin0TxISR, 0, ISR_PRIORITY_ASCLIN_TX)
{
  IfxAsclin_Asc_isrTransmit(&asclin);
}
IFX_INTERRUPT(asclin0RxISR, 0, ISR_PRIORITY_ASCLIN_RX)
{
  IfxAsclin_Asc_isrReceive(&asclin);
}

IFX_INTERRUPT(asclin0ErISR, 0, ISR_PRIORITY_ASCLIN_ER)
{
  IfxAsclin_Asc_isrError(&asclin);
}

static int uart_putc(char c)
{
  Ifx_SizeT count = 1;
  (void)IfxAsclin_Asc_write(&asclin, &c, &count, TIME_INFINITE);
  return 0;
}

static int uart_getc()
{
  int c;
  if (IfxAsclin_Asc_getReadCount(&asclin))
    c = IfxAsclin_Asc_blockingRead(&asclin);
  else
    c =-1;
  return c;
}


void serialio_init(void)
{
  IfxAsclin_Asc_Config ascConf;

  /* Set default configurations */
  IfxAsclin_Asc_initModuleConfig(&ascConf, &MODULE_ASCLIN0); /* Initialize the structure with default values      */

  /* Set the desired baud rate */
  ascConf.baudrate.baudrate = ASC_BAUDRATE;                        /* Set the baud rate in bit/s       */
  ascConf.baudrate.oversampling = IfxAsclin_OversamplingFactor_16; /* Set the oversampling factor      */

  /* Configure the sampling mode */
  ascConf.bitTiming.medianFilter = IfxAsclin_SamplesPerBit_three;          /* Set the number of samples per bit*/
  ascConf.bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_8; /* Set the first sample position    */

  /* ISR priorities and interrupt target */
  ascConf.interrupt.txPriority = ISR_PRIORITY_ASCLIN_TX; /* Set the interrupt priority for TX events             */
  ascConf.interrupt.rxPriority = ISR_PRIORITY_ASCLIN_RX; /* Set the interrupt priority for RX events             */
  ascConf.interrupt.erPriority = ISR_PRIORITY_ASCLIN_ER; /* Set the interrupt priority for Error events          */
  ascConf.interrupt.typeOfService = IfxSrc_Tos_cpu0;

  /* Pin configuration */
  const IfxAsclin_Asc_Pins pins = {.cts = NULL_PTR, /* CTS pin not used                                     */
                                   .ctsMode = IfxPort_InputMode_pullUp,
                                   .rx = &IfxAsclin0_RXD_P33_10_IN, /* Select the pin for RX connected to the USB port */
                                   .rxMode = IfxPort_InputMode_pullUp, /* RX pin */
                                   .rts = NULL_PTR, /* RTS pin not used                                     */
                                   .rtsMode = IfxPort_OutputMode_pushPull,
                                   .tx = &IfxAsclin0_TX_P33_9_OUT, /* Select the pin for TX connected to the USB port */
                                   .txMode = IfxPort_OutputMode_pushPull, /* TX pin */
                                   .pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1};
  ascConf.pins = &pins;

  /* FIFO buffers configuration */
  ascConf.txBuffer = TC_UartTxBuffer;        /* Set the transmission buffer                          */
  ascConf.txBufferSize = ASC_TX_BUFFER_SIZE; /* Set the transmission buffer size                     */
  ascConf.rxBuffer = TC_UartRxBuffer;        /* Set the receiving buffer                             */
  ascConf.rxBufferSize = ASC_RX_BUFFER_SIZE; /* Set the receiving buffer size                        */

  /* Init ASCLIN module */
  IfxAsclin_Asc_initModule(&asclin, &ascConf); /* Initialize the module with the given configuration   */
}


/* POSIX read function */
/* read characters from file descriptor fd into given buffer, at most count bytes */
/* returns number of characters in buffer */
size_t read(int fd, void* buffer, size_t count)
{
  size_t index = 0;

  if (fileno(stdin) == fd)
  {
    unsigned char* ptr = (unsigned char*)buffer;
    do
    {
      if (1 ==  uart_getc(ptr))
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
  }
  return index;
}

/* POSIX write function */
/* write content of buffer to file descriptor fd */
/* returns number of characters that have been written */
size_t write(int fd, const void* buffer, size_t count)
{
  size_t index = 0;
  if ((fileno(stdout) == fd) || (fileno(stderr) == fd))
  {
    const unsigned char* ptr = (const unsigned char*)buffer;
    while (index < count)
    {
      uart_putc(*ptr++);
      ++index;
    }
  }
  return index;
}

void _putchar(char ch)
{
#if 0
  while (IfxAsclin_getTxFifoFillLevelFlagStatus(SERIALIO.asclin) != TRUE)
    ;

  IfxAsclin_clearTxFifoFillLevelFlag(SERIALIO.asclin);

  /* send the character */
  IfxAsclin_writeTxData(SERIALIO.asclin, character);
#endif
  uart_putc(ch);
}

