#ifndef __LIB_BITS_WAITSTATUS_H__
# define __LIB_BITS_WAITSTATUS_H__

/* If WIFEXITED(STATUS), the low-order 8 bits of the status. */
#define	__WEXITSTATUS(status)	(((status) & 0xff00) >> 8)

/* If WIFSIGNALED(STATUS), the terminating signal. */
#define	__WTERMSIG(status)	((status) & 0x7f)

/* If WIFSTOPPED(STATUS), the signal that stopped the child. */
#define	__WSTOPSIG(status)	__WEXITSTATUS(status)

/* Nonzero if STATUS indicates normal termination. */
#define	__WIFEXITED(status)	(__WTERMSIG(status) == 0)

/* Nonzero if STATUS indicates termination by a signal. */
#define __WIFSIGNALED(status) \
  (((signed char) (((status) & 0x7f) + 1) >> 1) > 0)

/* Nonzero if STATUS indicates the child is stopped.  */
#define	__WIFSTOPPED(status)	(((status) & 0xff) == 0x7f)

/* Nonzero if STATUS indicates the child continued after a stop. */
# define __WIFCONTINUED(status)	((status) == __W_CONTINUED)

/* Nonzero if STATUS indicates the child dumped core.  */
#define	__WCOREDUMP(status)	((status) & __WCOREFLAG)

/* Macros for constructing status values.  */
#define	__W_EXITCODE(ret, sig)	((ret) << 8 | (sig))
#define	__W_STOPCODE(sig)	((sig) << 8 | 0x7f)
#define __W_CONTINUED		0xffff
#define	__WCOREFLAG		0x80

#endif /*__LIB_BITS_WAITSTATUS_H__*/
