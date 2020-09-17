#ifndef __LIB_FCNTL_H__
# define __LIB_FCNTL_H__

#include <stddef.h>
#include <stdint.h>

//TODO: update me !!
#define O_RDONLY	0
#define O_WRONLY	1
#define O_RDWR 		2

//TODO: define also in <stdio.h>
#define SEEK_SET	0	/* Seek from beginning of file.  */
#define SEEK_CUR	1	/* Seek from current position.  */
#define SEEK_END	2	/* Seek from end of file.  */

// Functions
extern int open(const char *pathname, int flags, ...);

#endif /*__LIB_FCNTL_H__*/
