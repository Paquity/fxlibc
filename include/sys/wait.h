#ifndef __LIB_SYS_WAIT_H__
# define __LIB_SYS_WAIT_H__

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <bits/waitflags.h>
#include <bits/waitstatus.h>

/* Macros for the `waitpid`'s wstatus argument. */
#define WEXITSTATUS(status)	__WEXITSTATUS(status)
#define WTERMSIG(status)	__WTERMSIG(status)
#define WSTOPSIG(status)	__WSTOPSIG(status)
#define WIFEXITED(status)	__WIFEXITED(status)
#define WIFSIGNALED(status)	__WIFSIGNALED(status)
#define WIFSTOPPED(status)	__WIFSTOPPED(status)
#define WIFCONTINUED(status)	__WIFCONTINUED(status)
#define WCOREDUMP(status)	__WCOREDUMP(status)

// Wait process
extern pid_t waitpid(pid_t pid, int *wstatus, int options);
extern pid_t wait(int *wstatus);

#endif /*__LIB_SYS_WAIT_H__*/
