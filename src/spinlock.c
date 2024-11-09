#include "spinlock.h"

#include <stdint.h>

void spinlock_lock(IfxCpu_spinLock *lock) {
  IfxCpu_disableInterrupts();
  IfxCpu_setSpinLock(lock, UINT32_MAX);
}

void spinlock_unlock(IfxCpu_spinLock *lock) {
  IfxCpu_resetSpinLock(lock);
  IfxCpu_enableInterrupts();
}
