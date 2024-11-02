#include "serial.h"

#include <stdio.h>>

int __getchar(void)
{
  char buf[2] = {0};
  int ch = serial_recv();
  if (ch == -1)
  {
    perror("Serial I/O error: __getchar");
    return (-1);
  }
  else if (ch == 0)
  {
    return (EOF);
  }
  else
  {
    return (ch);
  }
}
