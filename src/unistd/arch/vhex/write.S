#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_write
.type	_write, @function


.align 2
/*
** extern ssize_t write(int __fd, const void *__buf, size_t __nbytes);
** Write N bytes of BUF to FD.
** Return the number written, or -1.
*/
_write:
	trapa	#__NR_write
	rts
	nop
.end
#endif
