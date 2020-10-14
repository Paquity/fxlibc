#ifndef __LIB_SIGNAL_H__
# define __LIB_SIGNAL_H__

#include <stddef.h>
#include <stdint.h>
#include <bits/signum.h>

/* Type of signal set */
typedef uint32_t sigset_t;
typedef uint32_t kernel_sigset_t;

/* Type of a signal handler.*/
typedef void (*__sighandler_t)(int);
typedef __sighandler_t sighandler_t;

/*
** Get the system-specific definitions of `struct sigaction' and the `SA_*'
** and `SIG_*'. constants.
*/
#include <bits/sigaction.h>

/* Get and/or change the set of blocked signals.  */
extern int sigprocmask (int how, const sigset_t *restrict set, sigset_t *restrict oldset);

/*
** Send signal SIG to process number PID.  If PID is zero, send SIG to all
** processes in the current process's process group. If PID is < -1, send SIG to
** all processes in process group - PID.
*/
extern int kill(pid_t pid, int sig);

/*
** Set the handler for the signal SIG to HANDLER, returning the old handler, or
** SIG_ERR on error. By default `signal' has the BSD semantic.
*/
extern void (*signal(int signum, void (*handler)(int)))(int);

#endif /*__LIB_SIGNAL_H__*/
