#include <IfxCpu.h>
#include <IfxScuWdt.h>

#include "app.h"

IFX_ALIGN(4) IfxCpu_syncEvent cpuSyncEvent = 0;

void core0_main(void)
{
  /* Enable interrupts */
  IfxCpu_enableInterrupts();

  /* Disable CPU and safety watchdogs */
  IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
  IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

  /* Wait for CPU sync event */
  IfxCpu_emitEvent(&cpuSyncEvent);
  IfxCpu_waitEvent(&cpuSyncEvent, 1);

  /* Execute program logic */
  app_init();

  while (1)
  {
    app_poll();
  }
}
