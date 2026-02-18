#include "serial.h"
#include <stdio.h>
#include <sys/errno.h>

int write(int fd, const void* buffer, size_t size)
{
  int nwritten = size;
  uint8_t* ptr;
  if (fd <= 2)
  {
    ptr = (uint8_t*)buffer;
    while (size > 0)
    {
      if (*ptr == '\n')
      {
        serial_putc('\r');
        ++nwritten;
      }
      serial_putc(*ptr++);
      --size;
    }
  }
  else
  {
    errno = EIO;
    nwritten = -1;
  }
  return nwritten;
}

int __putchar(int ch)
{
  return write(stdout, &ch, 1);
}
