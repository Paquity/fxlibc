#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_setpgid
.type	_setpgid, @function


.align 2
/*
** extern int setpgid(pid_t __pid, pid_t __pgid);
** Set the process group ID of the process matching PID to PGID.
** If PID is zero, the current process's process group ID is set.
** If PGID is zero, the process ID of the process is used.
*/
_setpgid:
	trapa	#__NR_setpgid
	rts
	nop
.end
#endif
