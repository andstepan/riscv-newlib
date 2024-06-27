#include <machine/syscall.h>
#include <sys/types.h>
#include "internal_syscall.h"
#include "uart8250.h"
#include <unistd.h>

/* Write to a file.  */
ssize_t
write(int file, const void *ptr, size_t len)
{
  /** We can only write to STDOUT. Files are not supported. */
  if (file == STDOUT_FILENO)
  {

    /**
     * Write len amount of bytes to the UART output buffer. This 
     * is a non-blocking write, which means that when writing 
     * consecutuvely, the CPU has to busy-wait for the transmission
     * to finish before writing the next byte.
     */
    for(size_t i=0; i < len; i++)
    {
      uart8250_putc(((char*)ptr)[i]);
    }

    return 0;
  }
  else return syscall_errno(SYS_write, file, ptr, len, 0, 0, 0);
}
