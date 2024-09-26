#include "ASCLIN_LIN_Master.h"
#include "IfxCpu.h"
#include "IfxDts_Dts.h"
#include "IfxScuWdt.h"
#include "Ifx_Types.h"
#include "SysSe/Bsp/Bsp.h"
#include "board.h"
#include "can/can.h"
#include "serialio/serialio.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
/* Timer setup
 * set the values for systemtimer */
#define IFX_CFG_STM_TICKS_PER_MS (100000) /* Number of STM ticks per millisecond */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;
uint32 TickCount_1ms = 0;

/*********************************************************************************************************************/
/*----------------------------------------------Function Implementations---------------------------------------------*/
/*********************************************************************************************************************/
static void STM0_Init(void)
{
  /* initialize STM */
  IfxStm_CompareConfig stmCompareConfig;

  /* suspend by debugger enabled */
  IfxStm_enableOcdsSuspend(&MODULE_STM0);

  /* constructor of configuration */
  IfxStm_initCompareConfig(&stmCompareConfig);

  /* change the comparator configuration */
  stmCompareConfig.triggerPriority = ISR_PRIORITY_STM0_TICK;
  stmCompareConfig.comparatorInterrupt = IfxStm_ComparatorInterrupt_ir0; /*User must select the interrupt output */
  stmCompareConfig.ticks = IFX_CFG_STM_TICKS_PER_MS * 10;                /* we start after 10ms */
  stmCompareConfig.typeOfService = IfxSrc_Tos_cpu0;

  /* Now Compare functionality is initialized */
  IfxStm_initCompare(&MODULE_STM0, &stmCompareConfig);
}

/* This interrupt is raised by the STM1. The initialization is done in core1_main(). */
IFX_INTERRUPT(UsrIsr_Stm_0, 0, ISR_PRIORITY_STM0_TICK)
{
  /* Set next 1ms scheduler tick alarm */
  IfxStm_increaseCompare(&MODULE_STM0, IfxStm_Comparator_0, IFX_CFG_STM_TICKS_PER_MS);

  /* increment the ms value */
  TickCount_1ms++;

  /* Enable the global interrupts of this CPU */
  IfxCpu_enableInterrupts();

  /* action to do each 10ms */
  if ((TickCount_1ms % 10) == 0)
  {
  }

  /* action to do each 100ms */
  if ((TickCount_1ms % 100) == 0)
  {
  }

  /* action to do each 1s */
  if ((TickCount_1ms % 1000) == 0)
  {
    Power_Supply_Measurments();
    LED_Toggle(&LED_0); /* Toggle LED */
  }
}

/*********************************************************************************************************************/
/*---------------------------------------------- End of Function Implementations-------------------------------------*/
/*********************************************************************************************************************/
void core0_main(void)
{
  IfxCpu_enableInterrupts();

  /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
   * Enable the watchdogs and service them periodically if it is required
   */
  IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
  IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

  /* Wait for CPU sync event */
  IfxCpu_emitEvent(&g_cpuSyncEvent);
  IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

  /*init DTS */
  IfxDts_Dts_Config dtsConfig;
  IfxDts_Dts_initModuleConfig(&dtsConfig);

  IfxDts_Dts_initModule(&dtsConfig);

  serialio_init();
  printf("\n\n\n\n\n");
  printf("\n*******************************\n");
  printf("* Secure Gateway Example Project  *\n");
  printf("* Date: %10s           *\n", __DATE__);
  printf("*******************************\n");

  /* init LED0 */
  LED_Init(&LED_0);

  /* init the power supply status measurements */
  Init_Power_Supply_Measurments();

  /* initialize CAN module */
  initMcmcan();

  /* init STM0 */
  STM0_Init();

  /* init LIN2 */
  init_ASCLIN_LIN_master();

  /* send LIN header and data via LIN2 */
  send_ASCLIN_LIN_message();

  /* Send test message */
  transmitCanMessage();

  while (1)
  {
  }
}
