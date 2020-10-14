#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_signal
.type	_signal, @function


.align 2
/*
** extern void (*signal(int signum, void (*handler)(int)))(int);
** Set the handler for the signal SIG to HANDLER, returning the old handler, or
** SIG_ERR on error. By default `signal' has the BSD semantic.
*/
_signal:
	trapa	#__NR_signal
	rts
	nop
.end
#endif
