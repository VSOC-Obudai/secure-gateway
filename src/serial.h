#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>

#define SERIAL_BAUDRATE (115200)

#define SERIAL_TX_BUFFER_SIZE (64)
#define SERIAL_RX_BUFFER_SIZE (64)

#define ISR_PRIORITY_SERIAL_TX (1)
#define ISR_PRIORITY_SERIAL_RX (2)
#define ISR_PRIORITY_SERIAL_ER (3)

extern void serial_init(void);
extern int serial_recv(void);
extern void serial_send(int ch);

#endif /* SERIAL_H */
