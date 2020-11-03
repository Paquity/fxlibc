#ifdef __SUPPORT_VHEX_KERNEL
#include <fxlibc/asm/unistd.h>
.text
.global	_close
.type	_close, @function


.align 2
/*
** int close(int fd)
** close() closes a file descriptor, so that it no longer refers to any file
** and may be reused.
*/
_close:
	trapa	#__NR_close
	rts
	nop
.end
#endif
