#include <asm/unistd_32.h>
.text
.global	_getppid
.type	_getppid, @function


.align 2
_getppid:
	trapa	#__NR_getppid
	rts
	nop
.end
