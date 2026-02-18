#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>

/*!
 * @brief Initializes the serial I/O.
 */
void serial_init(void);

/*!
 * @brief Inputs a new character.
 * @return A new character.
 */
int serial_getc(void);

/*!
 * @brief Outputs a new character.
 * @param c The new character.
 * @return The error state of the function.
 */
int serial_putc(uint8_t c);

#endif /* SERIAL_H */
