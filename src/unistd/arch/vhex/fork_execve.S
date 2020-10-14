#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_fork_execve
.type	_fork_execve, @function


.align 2
/*
** pid_t fork_execve(const char *pathname, char **argv, char **envp);
** Custom syscall used to create a new process based on the new command passed
** using the `argv` and `envp` parametter. This sycall is equivalent of fork()
** and execve() combined.
**
** This custom syscall exist because the Vhex kernel doesn't have access to the
** MMU, so we cannot ensure that the memory requested by the potential new
** process is enough when execve() is involved by the user.
*/
_fork_execve:
	trapa	#__NR_fork_execve
	rts
	nop
.end
#endif
