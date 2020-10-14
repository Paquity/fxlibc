#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_lseek
.type	_lseek, @function


.align 2
/*
** extern off_t lseek(int fd, off_t offset, int whence)
** Move FD's file position to OFFSET bytes from the beginning of the file
** (if WHENCE is SEEK_SET), the current position (if WHENCE is SEEK_CUR),
** or the end of the file (if WHENCE is SEEK_END).
** Return the new file position.
*/
_lseek:
	trapa	#__NR_lseek
	rts
	nop
.end
#endif
