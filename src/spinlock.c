#include "spinlock.h"

#include <stdint.h>

boolean spinlock_lock(IfxCpu_spinLock *lock) {
  boolean ie = IfxCpu_disableInterrupts();
  IfxCpu_setSpinLock(lock, UINT32_MAX);
  return ie;
}

void spinlock_unlock(IfxCpu_spinLock *lock, boolean saved_ie) {
  IfxCpu_resetSpinLock(lock);
  if (saved_ie) {
    IfxCpu_enableInterrupts();
  }
}
