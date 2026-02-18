#ifndef TIMER_H
#define TIMER_H

/*!
 * @brief Initializes the device timer.
 */
void timer_init(void);

/*!
 * @brief Gets the current time in milliseconds.
 * @return The current time in milliseconds.
 */
unsigned long timer_get(void);

#endif /* TIMER_H */
