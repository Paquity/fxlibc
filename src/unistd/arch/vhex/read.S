#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_read
.type	_read, @function


.align 2
/*
** extern ssize_t write(int __fd, const void *__buf, size_t __nbytes);
** Write N bytes of BUF to FD.
** Return the number written, or -1.
*/
_read:
	trapa	#__NR_read
	rts
	nop
.end
#endif
