#ifndef __LIB_FCNTL_H__
# define __LIB_FCNTL_H__

#include <stddef.h>
#include <stdint.h>

/* also defined in <stdio.h> */
#define SEEK_SET	0	/* Seek from beginning of file.  */
#define SEEK_CUR	1	/* Seek from current position.  */
#define SEEK_END	2	/* Seek from end of file.  */

/*
** Open FILE and return a new file descriptor for it, or -1 on error.
** OFLAG determines the type of access used.  If O_CREAT or O_TMPFILE is set
** in OFLAG, the third argument is taken as a `mode_t', the mode of the
** created file.
*/
extern int open(const char *pathname, int flags, ...);

#endif /*__LIB_FCNTL_H__*/
