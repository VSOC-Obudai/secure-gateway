#ifndef SPINLOCK_H
#define SPINLOCK_H

#include <IfxCpu.h>

/*!
 * @brief Lock the spin-lock and disable hardware interrupts.
 * @param lock The pointer to spin-lock type.
 */
void spinlock_lock(IfxCpu_spinLock *lock);

/*!
 * @brief Unlocks the spin-lock and re-enable hardware interrupts.
 * @param lock The pointer to spin-lock type.
 */
void spinlock_unlock(IfxCpu_spinLock* lock);

#endif /* SPINLOCK_H */
