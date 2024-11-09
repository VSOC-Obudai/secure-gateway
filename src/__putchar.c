#include "serial.h"
#include <stdio.h>
#include <sys/errno.h>

int write(int fd, const void* buffer, size_t size)
{
  int snd;
  uint8_t* ptr;
  if (fd <= 2)
  {
    snd = size;
    ptr = (uint8_t*)buffer;
    while (size > 0)
    {
      if (*ptr == '\n')
      {
        serial_putc('\r');
      }
      serial_putc(*ptr++);
      ++snd;
      --size;
    }
  }
  else
  {
    errno = EIO;
    snd = -1;
  }
  return snd;
}

int __putchar(int ch)
{
  return write(stdout, &ch, 1);
}
