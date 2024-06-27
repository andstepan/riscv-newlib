#include <machine/syscall.h>
#include "internal_syscall.h"

/* Create a new process. Minimal implementation for a system without
   processes from newlib documentation.  */
int fork()
{
  errno = EAGAIN;
  return -1;
}
