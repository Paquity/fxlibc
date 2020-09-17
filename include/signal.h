#ifndef __LIB_SIGNAL_H__
# define __LIB_SIGNAL_H__

#include <stddef.h>
#include <stdint.h>
#include <bits/signum.h>

// Type of a signal handler
typedef void (*__sighandler_t)(int);
typedef __sighandler_t sighandler_t;

// Type of signal set
typedef uint32_t sigset_t;
typedef uint32_t kernel_sigset_t;

// Define sigprocmask() value for "how" argument
#define SIG_BLOCK	0
#define SIG_UNBLOCK	1
#define SIG_SETMASK	2

// Prototype
// TODO: doc
extern int kill(pid_t pid, int sig);
extern void (*signal(int signum, void (*handler)(int)))(int);

#endif /*__LIB_SIGNAL_H__*/
