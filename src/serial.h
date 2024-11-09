#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>

/*!
 * @brief
 */
void serial_init(void);

/*!
 * @brief
 * @return
 */
int serial_getc(void);

/*!
 * @brief
 * @param c
 * @return
 */
int serial_putc(uint8_t c);

#endif /* SERIAL_H */
