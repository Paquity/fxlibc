#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_getpgid
.type	_getpgid, @function


.align 2
/*
** extern pid_t getpgid(void);
** Get the process group ID of the calling process.
*/
_getpgid:
	trapa	#__NR_getpgid
	rts
	nop
.end
#endif
