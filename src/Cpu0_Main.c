#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Ifx_Types.h"

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

  /* Start and run program logic */
  app_init();
  app_run();

  /* Normally program flow should not reach here */
  while (1)
    ;
}
