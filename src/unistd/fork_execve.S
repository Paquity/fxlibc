#include <asm/unistd_32.h>
.text
.global	_fork_execve
.type	_fork_execve, @function


.align 2
_fork_execve:
	trapa	#__NR_fork_execve
	rts
	nop
.end
