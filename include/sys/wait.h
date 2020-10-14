#ifndef __LIB_SYS_WAIT_H__
# define __LIB_SYS_WAIT_H__

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

/*
** This will define the `W*' macros for the flag bits to `waitpid', `wait3',
** and `wait4'.
*/
#include <bits/waitflags.h>

/* This will define all the `__W*' macros.*/
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

/*
** Wait for a child matching PID to die.
** - If PID is greater than 0, match any process whose process ID is PID.
** - If PID is (pid_t) -1, match any process.
** - If PID is (pid_t) 0, match any process with the same process group as the
**   current process.
** - If PID is less than -1, match any process whose process group is the absolute
**   value of PID.
** - If the WNOHANG bit is set in OPTIONS, and that child is not already dead,
**   return (pid_t) 0.  If successful, return PID and store the dead child's
**   status in STAT_LOC.
** - Return (pid_t) -1 for errors.  If the WUNTRACED bit is set in OPTIONS,
**   return status for stopped children; otherwise don't.
*/
extern pid_t waitpid(pid_t pid, int *wstatus, int options);

/*
** Wait for a child to die.  When one does, put its status in *STAT_LOC
** and return its process ID.  For errors, return (pid_t) -1.
*/
extern pid_t wait(int *wstatus);

#endif /*__LIB_SYS_WAIT_H__*/
