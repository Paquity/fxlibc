#ifndef __LIB_BITS_WAITFLAGS_H__
# define __LIB_BITS_WAITFLAGS_H__

/* Bits in the third argument to `waitpid'. */
#define	WNOHANG		1	/* Don't block waiting. */
#define	WUNTRACED	2	/* Report status of stopped child. */
#define	WCONTINUED	3	/* Report continued child. */

#endif /*__LIB_BITS_WAITFLAGS_H__*/
