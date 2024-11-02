#include "app.h"

#include "can.h"
#include "serial.h"
#include "stm.h"

#include <stdio.h>

void app_show_logo(void)
{
  printf("                                                                                              BUILD %10s\n", __DATE__);
  printf("░▒▓█▓▒░░▒▓█▓▒░ ░▒▓███████▓▒░ ░▒▓██████▓▒░  ░▒▓██████▓▒░        ░▒▓██████▓▒░░▒▓████████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░\n");
  printf("░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░       ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒░    ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░\n");
  printf(" ░▒▓█▓▒▒▓█▓▒░ ░▒▓█▓▒░       ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░             ░▒▓█▓▒░         ░▒▓█▓▒░    ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░\n");
  printf(" ░▒▓█▓▒▒▓█▓▒░  ░▒▓██████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░             ░▒▓█▓▒▒▓███▓▒░  ░▒▓█▓▒░    ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░\n");
  printf("  ░▒▓█▓▓█▓▒░         ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒░    ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░\n");
  printf("  ░▒▓█▓▓█▓▒░         ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒░    ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░\n");
  printf("   ░▒▓██▓▒░   ░▒▓███████▓▒░  ░▒▓██████▓▒░  ░▒▓██████▓▒░        ░▒▓██████▓▒░   ░▒▓█▓▒░     ░▒▓█████████████▓▒░\n\n");
  printf("                                S E C U R I T Y   G A T E W A Y   F I R M W A R E\n");
  printf("                                -------------------------------------------------\n");
  printf("                                         Designed to Protect and Monitor\n");
  printf("                                     Embedded Security in Automotive Systems\n");
  printf("\n\n");
}

void app_init(void)
{
  serial_init();
  app_show_logo();
  stm_init();
  can_init();
}

void app_run(void)
{
  while (true)
  {
    stm_update();
  }
}
