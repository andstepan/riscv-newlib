#include <machine/syscall.h>
#include <sys/types.h>
#include "internal_syscall.h"
#include "uart8250.h"

/* Write to a file.  */
ssize_t
_write(int file, const void *ptr, size_t len)
{
  for(size_t i=0; i < len; i++)
  {
    uart8250_putc(((char*)ptr)[i]);
  }
  return 0;
}
