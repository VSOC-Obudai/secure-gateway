#include "timer.h"

#include <IfxCpu_Irq.h>
#include <IfxStm.h>

volatile unsigned long ms_count;
volatile unsigned long ticks_per_ms;

IFX_INTERRUPT(timer_isr_tick_handler, 0, ISR_PRIORITY_STM0_TICK)
{
  unsigned long free_running_counter_now;
  unsigned long compare_counter;
  unsigned long delta_counts;

  ++ms_count;

  IfxStm_increaseCompare(&MODULE_STM0, IfxStm_Comparator_0, ticks_per_ms);

  free_running_counter_now = IfxStm_getLower(&MODULE_STM0);
  compare_counter = IfxStm_getCompare(&MODULE_STM0, IfxStm_Comparator_0);
  delta_counts = compare_counter - free_running_counter_now;

  if (delta_counts > ticks_per_ms)
  {
    IfxStm_updateCompare(&MODULE_STM0, IfxStm_Comparator_0, free_running_counter_now + ticks_per_ms);
  }

  IfxStm_clearCompareFlag(&MODULE_STM0, IfxStm_Comparator_0);
}

void timer_init()
{
  IfxStm_CompareConfig config;
  ms_count = 0;
  ticks_per_ms = IfxStm_getTicksFromMilliseconds(&MODULE_STM0, 1);
  IfxStm_enableOcdsSuspend(&MODULE_STM0);
  IfxStm_initCompareConfig(&config);
  config.comparator = IfxStm_Comparator_0;
  config.comparatorInterrupt = IfxStm_ComparatorInterrupt_ir0;
  config.compareOffset = IfxStm_ComparatorOffset_0;
  config.compareSize = IfxStm_ComparatorSize_32Bits;
  config.triggerPriority = ISR_PRIORITY_STM0_TICK;
  config.typeOfService = IfxSrc_Tos_cpu0;
  config.ticks = ticks_per_ms;
  IfxStm_initCompare(&MODULE_STM0, &config);
}

unsigned long timer_get()
{
  return ms_count;
}
