#include <machine/syscall.h>
#include <sys/types.h>
#include "internal_syscall.h"
#include "uart8250.h"
#include "unistd.h"

/* Read from a file.  */
ssize_t read(int file, void *ptr, size_t len)
{
  /** We can only read from STDIN. Files are not supported. */
  if (file == STDIN_FILENO)
  {
    /** 
     * Read EXACTLY len bytes from STDIN and write them 
     * to ptr 
     */
    ssize_t i = 0;
    while (i < len)
    {
      /** Stores data read from UART */ 
      char uart_data;
      
      /**
       * Try to read until a character is read. getc is a
       * non-blocking operation, which means that whenever 
       * we read something from the UART buffer while it is 
       * empty, we get -1 as the result. So, we poll-read 
       * a len amount of bytes.
       */
      while(1)
      {
        uart_data = uart8250_getc();
        if (uart_data != -1) break;
      }

      ((char*)ptr)[i++] = uart_data;
    }

    return 0;
  }
  else return syscall_errno (SYS_read, file, ptr, len, 0, 0, 0);
}
