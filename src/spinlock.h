#ifndef SPINLOCK_H
#define SPINLOCK_H

#include <IfxCpu.h>

/*!
 * @brief Lock the spin-lock and disable hardware interrupts.
 * @param lock The pointer to spin-lock type.
 * @return The previous interrupt-enable state (to be passed to spinlock unlock).
 */
boolean spinlock_lock(IfxCpu_spinLock *lock);

/*!
 * @brief Unlocks the spin-lock and re-enable hardware interrupts.
 * @param lock The pointer to spin-lock type.
 * @param saved_ie The interrupt-enable state returned by spinlock lock.
 */
void spinlock_unlock(IfxCpu_spinLock* lock, boolean saved_ie);

#endif /* SPINLOCK_H */
