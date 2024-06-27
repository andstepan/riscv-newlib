#include <machine/syscall.h>
#include <errno.h>

/* Wait for a child process. Minimal implementation for a system without
   processes just causes an error.  */
int wait(int *status)
{
  errno = ECHILD;
  return -1;
}
