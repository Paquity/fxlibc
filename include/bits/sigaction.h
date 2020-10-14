#ifndef __BITS_SIGACTION_H__
# define __BITS_SIGACTION_H__

#include <stddef.h>
#include <stdint.h>

/* Values for the HOW argument to `sigprocmask'. */
#define SIG_BLOCK	0	/* Block signals. */
#define SIG_UNBLOCK	1	/* Unblock signals. */
#define SIG_SETMASK	2	/* Set the set of blocked signals. */

#endif /*__BITS_SIGACTION_H__*/
