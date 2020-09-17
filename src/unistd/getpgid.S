#include <asm/unistd_32.h>
.text
.global	_getpgid
.type	_getpgid, @function


.align 2
_getpgid:
	trapa	#__NR_getpgid
	rts
	nop
.end
