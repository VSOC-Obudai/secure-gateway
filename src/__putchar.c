#include "serial.h"

#include <stdio.h>

void __putchar(int ch)
{
  if (ch == '\n')
  {
    serial_send('\n');
    serial_send('\r');
  }
  else
  {
    serial_send(ch);
  }
}
