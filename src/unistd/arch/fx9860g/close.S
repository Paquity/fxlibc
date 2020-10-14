#ifdef __SUPPORT_CASIO_ABI_FX9860G
#include <asm/unistd_32.h>
#include <asm-casio/__trapa.h>
.text
.global	_close
.type	_close, @function


.align 2
/*
** int close(int fd)
** close() closes a file descriptor, so that it no longer refers to any file
** and may be reused.
*/
_close:
	casio_trapa(__NR_Bfile_CloseFile)
	rts
	nop
.end
#endif
