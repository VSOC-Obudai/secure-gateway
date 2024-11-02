#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Ifx_Types.h"

extern IfxCpu_syncEvent cpuSyncEvent;

void core2_main(void)
{
  /* Enable interrupts */
  IfxCpu_enableInterrupts();

  /* Disable CPU watchdog */
  IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());

  /* Wait for CPU sync event */
  IfxCpu_emitEvent(&cpuSyncEvent);
  IfxCpu_waitEvent(&cpuSyncEvent, 1);

  /* Normally program flow should not reach here */
  while (1)
    ;
}
