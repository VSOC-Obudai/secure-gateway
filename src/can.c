/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "can.h"

#include "config.h"
#include "led.h"
#include "isr_config.h"
#include "serial.h"
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

IFX_INTERRUPT(can_irq_comm_error, 0, ISR_PRIORITY_CAN_COMM_ERROR) {
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

/*!
 * @brief Prints a given literal string to the output.
 *
 * Walks the null-terminated string byte by byte.
 * For each character, if it is '\n' it first emits a '\r' (so the terminal moves to column zero
 * before the newline), then emits the character itself. This replicates the \n to \r\n translation
 * that __putchar.c's write() function used to do.
 * This function is used to print literal strings like "TX", " | ", or "!! ", and the error
 * descriptions.
 * @param s The string literal to output.
 */
static void _serial_str(const char* s) {
  while (*s) {
    if (*s == '\n') serial_putc('\r');
    serial_putc((uint8_t)*s++);
  }
}

/*!
 * @brief Prints an 8-bit long hexadecimal integer.
 * 
 * Prints one byte as exactly two uppercase hex digits. It splits the byte into two 4-bit nibbles:
 * - v >> 4 — the high nibble (bits 7–4), used as an index into the lookup table for the first digit
 * - v & 0xF — the low nibble (bits 3–0), for the second digit
 * For example, 0xB2 to high nibble 0xB to 'B', low nibble 0x2 to '2', output B2.
 * Used for each byte of the CAN frame payload (replacing printf(" %02X", ...)).
 *
 * @param v An 8-bit long hexadecimal integer.
 */
static void _serial_hex8(uint8_t v) {
  static const char hex[] = "0123456789ABCDEF";
  serial_putc((uint8_t)hex[v >> 4]);
  serial_putc((uint8_t)hex[v & 0xF]);
}

/*!
 * @brief Prints an 32-bit long hexadecimal integer.
 * 
 * Prints a 32-bit value as 0x followed by exactly 8 uppercase hex digits.
 * The loop runs 8 times with i stepping 28 to 24 to 16 to ... to 0 (four bits per step).
 * Each iteration right-shifts v by i bits to bring the target nibble into the lowest 4 bits,
 * then masks with 0xF to isolate it, and uses it as the lookup index.
 * The most-significant nibble is printed first because i starts at 28.
 *
 * For example, 123 (decimal) → 0x0000007B.
 * Replaces printf("0x%08lX", frame->can_id).
 *
 * @param v A 32-bit long hexadecimal integer.
 */
static void _serial_hex32(uint32_t v) {
  static const char hex[] = "0123456789ABCDEF";
  serial_putc('0'); serial_putc('x');
  for (int i = 28; i >= 0; i -= 4) {
    serial_putc((uint8_t)hex[(v >> i) & 0xF]);
  }
}

/*!
* @brief Formats and transmits a single CAN frame to the UART as a fixed-
*        layout human-readable line, safe for use from both task and ISR
*        contexts.
*
* Output format (one line per call, terminated with CR LF):
*
*   <prefix> | 0x<IIIIIIII> | <B0> <B1> ... <Bn-1>\r\n
*
* where:
*   <prefix>         is the caller-supplied direction tag (e.g. "TX" or "RX"),
*                    emitted verbatim with LF-to-CRLF translation applied.
*   0x<IIIIIIII>     is @c frame->can_id printed as exactly 8 uppercase hex
*                    digits with the "0x" prefix, always 10 characters wide.
*   <B0>..<Bn-1>     are @c frame->len payload bytes from @c frame->data[],
*                    each printed as exactly 2 uppercase hex digits, each
*                    preceded by a single space character. No byte is printed
*                    if @c frame->len is 0.
*
* Example — TX frame, CAN ID 0x7B (decimal 123), 8 bytes of payload:
*
*   TX | 0x0000007B | 0F 00 00 0D 0B 0A 0B 0E\r\n
*
* Thread/ISR safety:
*   The entire output sequence is bracketed by spinlock_lock() and
*   spinlock_unlock() on @c can_device.lock. spinlock_lock() saves the
*   current interrupt-enable state and disables interrupts; spinlock_unlock()
*   restores (not unconditionally re-enables) that saved state. This prevents
*   interleaved output from concurrent callers and ensures the function does
*   not alter the ambient interrupt state when called from ISR context. All
*   UART output is performed through serial_putc(), which operates directly
*   on the ASCLIN TXDATA hardware register and carries no FILE* or newlib
*   internal state.
*
* @param prefix  Null-terminated string used as the direction tag at the
*                start of the output line. Must not be NULL. Typically "TX"
*                or "RX".
* @param frame   Pointer to the CAN frame to print. Must not be NULL.
*                @c frame->can_id is printed in full, including any EFF,
*                RTR, or ERR flag bits occupying bits 31:29. @c frame->len
*                must be in the range [0, CAN_MAX_DLEN] (0–8 inclusive);
*                only the first @c frame->len bytes of @c frame->data[] are
*                accessed and printed.
*/
static void _can_message_print(const char *const prefix, const can_frame_t *const frame) {
  boolean ie = spinlock_lock(&can_device.lock);
  _serial_str(prefix);
  _serial_str(" | ");
  _serial_hex32(frame->can_id);
  _serial_str(" |");
  for (uint8_t i = 0; i < frame->len; ++i) {
    serial_putc(' ');
    _serial_hex8(frame->data[i]);
  }
  serial_putc('\r'); serial_putc('\n');
  spinlock_unlock(&can_device.lock, ie);
}

/*!
* @brief Transmits a human-readable diagnostic string for a CAN protocol
*        error to the UART, safe for use from both task and ISR contexts.
*
* If @p error_code is 0 the function returns immediately without producing
* any UART output (code 0 means no error). For any non-zero value the
* function emits a "!! " prefix, then the diagnostic string corresponding
* to the current error, then CR LF (\r\n), for a total of one output line.
*
* Output format:
*
*   !! <diagnostic-string>\r\n
*
* The diagnostic string is selected by indexing the internal @c error_strings
* table with @c (uint32_t)can_device.er, NOT with @p error_code directly.
* The cast to @c uint32_t converts the @c IfxCan_LastErrorCodeType enum to
* an array index. In normal usage the caller assigns @c can_device.er and
* then passes that same value as @p error_code, so the two are identical at
* the point of the call. Nevertheless, the authoritative source for the
* string selection is @c can_device.er; @p error_code serves only as the
* zero/non-zero output guard.
*
* Valid @c can_device.er values and their corresponding strings:
*   0 — No error (output suppressed by the @p error_code guard)
*   1 — Bit stuffing error
*   2 — Form error
*   3 — ACK error
*   4 — Bit error (expected recessive, read dominant)
*   5 — Bit error (expected dominant, read recessive)
*   6 — CRC error
*   7 — CAN bus error (no activity detected)
*
* Passing a value of @c can_device.er outside [0, 7] produces undefined
* behaviour due to out-of-bounds array access.
*
* Thread/ISR safety:
*   Identical to _can_message_print(): the output sequence is guarded by
*   spinlock_lock() / spinlock_unlock() on @c can_device.lock with
*   interrupt-state save and restore, and all output is routed through
*   serial_putc() with no FILE* or newlib internal state involved.
*
* @param error_code  The error code to evaluate. Used only as a zero /
*                    non-zero guard to suppress output when no error is
*                    present. Must be in the range [0, 7] and must equal
*                    @c can_device.er at the time of the call.
*/
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
    boolean ie = spinlock_lock(&can_device.lock);
    _serial_str("!! ");
    _serial_str(error_strings[(uint32_t)can_device.er]);
    serial_putc('\r'); serial_putc('\n');
    spinlock_unlock(&can_device.lock, ie);
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

  IfxPort_setPinModeInput(DEFAULT_CAN_RX_PIN.pin.port, DEFAULT_CAN_RX_PIN.pin.pinIndex, IfxPort_InputMode_pullUp);

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
