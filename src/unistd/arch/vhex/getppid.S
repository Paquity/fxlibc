#ifdef __SUPPORT_VHEX_KERNEL
#include <fxlibc/asm/unistd.h>
.text
.global	_getppid
.type	_getppid, @function


.align 2
/*
** extern pid_t getpgid(void);
** Get the parent process ID of the calling process.
*/
_getppid:
	trapa	#__NR_getppid
	rts
	nop
.end
#endif
