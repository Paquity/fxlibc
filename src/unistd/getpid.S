#include <asm/unistd_32.h>
.text
.global	_getpid
.type	_getpid, @function


.align 2
_getpid:
	trapa	#__NR_getpid
	rts
	nop
.end
