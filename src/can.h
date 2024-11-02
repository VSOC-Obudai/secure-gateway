#ifndef CAN_H
#define CAN_H

#include <stdint.h>

#define ISR_PRIORITY_CAN_TX (4)
#define ISR_PRIORITY_CAN_RX (5)

#define CAN_TX_BUFFER_SIZE (64)
#define CAN_RX_BUFFER_SIZE (64)

#define CAN_BAUDRATE (500000)

#if (defined(CAN_EXTENDED_FORMAT) && (CAN_EXTENDED_FORMAT == 1))
#define CAN_TX_PAYLOAD_SIZE (16)
#define CAN_RX_PAYLOAD_SIZE (16)
#else
#define CAN_TX_PAYLOAD_SIZE (2)
#define CAN_RX_PAYLOAD_SIZE (2)
#endif

typedef struct
{
  uint32_t id;
  uint8_t size;
  uint8_t data[8];
} can_frame_t;

extern void can_init(void);
extern void can_send(const can_frame_t* const frame);
extern void can_recv(can_frame_t *frame);

#endif /* CAN_H */
