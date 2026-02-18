#include "serial.h"

#include <stdio.h>
#include <errno.h>

int read(int fd, const void* buffer, size_t size)
{
  int nread = 0;
  uint8_t* ptr;
  if (fd <= 2)
  {
    ptr = (uint8_t*)buffer;
    while (size > 0)
    {
      *ptr = serial_getc();
      if (*ptr == '\r')
      {
        *ptr = '\n';
      }
      ++nread;
      --size;
    }
  }
  else
  {
    nread = -1;
    errno = EIO;
  }
  return nread;
}

int __getchar()
{
  char c = 0;
  read(stdin, &c, 1);
  return c;
}
