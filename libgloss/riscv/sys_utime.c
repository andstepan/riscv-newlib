#include <machine/syscall.h>

/* Stub.  */
int
utime(const char *path, const struct utimbuf *times)
{
  return -1;
}
