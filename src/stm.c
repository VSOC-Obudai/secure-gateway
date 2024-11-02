#include "stm.h"

#include "SysSe/Bsp/Bsp.h"
#include <Stm/Std/IfxStm.h>
#include <Stm/Timer/IfxStm_Timer.h>

#define STM_PORT_ADDR (&MODULE_STM0)

typedef struct
{
  Ifx_STM* handle;
  IfxStm_Timer timer;
  IfxStm_CompareConfig config;
  volatile uint32_t ticks;
} stm_device_t;

stm_device_t stm_device;
stm_info_t stm_info;

IFX_INTERRUPT(isr_stm_ticks_handler, 0, ISR_PRIORITY_STM_TICKS)
{
  IfxCpu_enableInterrupts();
  IfxStm_clearCompareFlag(stm_device.handle, stm_device.config.comparator);
  IfxStm_increaseCompare(stm_device.handle, stm_device.config.comparator, IFX_CFG_STM_TICKS_PER_MS);
  stm_device.ticks++;
  if (stm_device.ticks == 1000)
  {
    stm_device.ticks = 0;
  }

  /* 1s */
  stm_info.flag_1ms = true;

  /* 10ms */
  if (stm_device.ticks % 10 == 0)
  {
    stm_info.flag_10ms = true;
  }

  /* 100ms */
  if (stm_device.ticks % 100 == 0)
  {
    stm_info.flag_100ms = true;
  }

  /* 1000ms */
  if (stm_device.ticks % 1000 == 0)
  {
    stm_info.flag_1000ms = true;
  }
}

void stm_init()
{
  stm_reset();
  boolean interruptState = IfxCpu_disableInterrupts();
  IfxStm_enableOcdsSuspend(stm_device.handle);
  IfxStm_initCompareConfig(&stm_device.config);
  stm_device.config.triggerPriority = ISR_PRIORITY_STM_TICKS;
  stm_device.config.comparatorInterrupt = IfxStm_ComparatorInterrupt_ir0;
  stm_device.config.ticks = IFX_CFG_STM_TICKS_PER_MS;
  stm_device.config.typeOfService = IfxSrc_Tos_cpu0;
  IfxStm_initCompare(stm_device.handle, &stm_device.config);
  IfxCpu_restoreInterrupts(interruptState);
}

void stm_update()
{
  /* 1ms */
  if (stm_info.flag_1ms)
  {
    stm_info.flag_1ms = false;
  }
  /* 10ms */
  if (stm_info.flag_10ms)
  {
    stm_info.flag_10ms = false;
  }
  /* 100ms */
  if (stm_info.flag_100ms)
  {
    stm_info.flag_100ms = false;
  }
  /* 1000ms */
  if (stm_info.flag_1000ms)
  {
    stm_info.flag_1000ms = false;
  }
}

void stm_reset()
{
  stm_device.handle = STM_PORT_ADDR;
  stm_device.ticks = 0;
  IfxStm_resetModule(stm_device.handle);
}

void stm_wait(uint32_t ms)
{
  waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, ms));
}
