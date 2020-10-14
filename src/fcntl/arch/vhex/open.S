#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_open
.type	_open, @function


.align 2
/*
** extern int open(const char *pathname, int flags, ...);
** Open FILE and return a new file descriptor for it, or -1 on error.
** OFLAG determines the type of access used.  If O_CREAT or O_TMPFILE is set
** in OFLAG, the third argument is taken as a `mode_t', the mode of the
** created file.
*/
_open:
	trapa	#__NR_open
	rts
	nop
.end
#endif
