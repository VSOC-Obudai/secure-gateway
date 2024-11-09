#include "app.h"
#include "can.h"
#include "config.h"
#include "serial.h"
#include "timer.h"

#include <SysSe/Bsp/Bsp.h>

#include <stdio.h>

void app_show_logo(void) {
  printf("                                             BUILD %10s\n", __DATE__);
  printf("-------------------------------------------------------------\n");
  printf(" ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓███████▓▒░ ░▒▓████████▓▒░  ░▒▓██████▓▒░  \n");
  printf(" ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ \n");
  printf("  ░▒▓█▓▒▒▓█▓▒░  ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        \n");
  printf("  ░▒▓█▓▒▒▓█▓▒░   ░▒▓██████▓▒░  ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        \n");
  printf("   ░▒▓█▓▓█▓▒░          ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        \n");
  printf("   ░▒▓█▓▓█▓▒░          ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ \n");
  printf("    ░▒▓██▓▒░    ░▒▓███████▓▒░  ░▒▓████████▓▒░  ░▒▓██████▓▒░  \n");
  printf("                                                             \n");
  printf("                                                             \n");
  printf("      ░▒▓██████▓▒░  ░▒▓████████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░     \n");
  printf("     ░▒▓█▓▒░░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░     \n");
  printf("     ░▒▓█▓▒░           ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░     \n");
  printf("     ░▒▓█▓▒▒▓███▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░     \n");
  printf("     ░▒▓█▓▒░░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░     \n");
  printf("     ░▒▓█▓▒░░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░     \n");
  printf("      ░▒▓██████▓▒░     ░▒▓█▓▒░      ░▒▓█████████████▓▒░      \n");
  printf("-------------------------------------------------------------\n");
  printf("      S E C U R I T Y   G A T E W A Y   F I R M W A R E      \n");
  printf("-------------------------------------------------------------\n");
  printf("             Designed to Protect and Monitor                 \n");
  printf("          Embedded Security in Automotive Systems            \n");
  printf("-------------------------------------------------------------\n");
}

void app_init(void) {
  can_frame_t dummy = { .can_id = 111, .len = 8, .data = {0xd,0xe,0xa,0xd,0xb,0xe,0xe,0xf} };
  serial_init();
  app_show_logo();
  timer_init();
  can_init();
  waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 10));
  can_send(&dummy);
}

void app_poll(void) {}
