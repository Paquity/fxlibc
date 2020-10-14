#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_getpid
.type	_getpid, @function


.align 2
/*
** extern pid_t getpid(void);
** Get the process ID of the calling process.
*/
_getpid:
	trapa	#__NR_getpid
	rts
	nop
.end
#endif
