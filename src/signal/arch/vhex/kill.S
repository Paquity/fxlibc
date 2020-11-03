#ifdef __SUPPORT_VHEX_KERNEL
#include <fxlibc/asm/unistd_32.h>
.text
.global	_kill
.type	_kill, @function


.align 2
/*
** extern int kill(pid_t pid, int sig);
** Send signal SIG to process number PID.  If PID is zero, send SIG to all
** processes in the current process's process group. If PID is < -1, send SIG to
** all processes in process group - PID.
*/
_kill:
	trapa	#__NR_kill
	rts
	nop
.end
#endif
