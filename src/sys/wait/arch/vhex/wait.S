#ifdef __SUPPORT_VHEX_KERNEL
#include <fxlibc/asm/unistd.h>
.text
.global	_wait
.type	_wait, @function


.align 2
/*
** extern pid_t wait(int *wstatus);
** Wait for a child to die.  When one does, put its status in *STAT_LOC
** and return its process ID.  For errors, return (pid_t) -1.
*/
_wait:
	trapa	#__NR_wait
	rts
	nop
.end
#endif
