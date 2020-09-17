#include <asm/unistd_32.h>
.text
.global	_wait
.type	_wait, @function


.align 2
_wait:
	trapa	#__NR_wait
	rts
	nop
.end
