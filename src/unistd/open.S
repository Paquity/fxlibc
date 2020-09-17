#include <asm/unistd_32.h>
.text
.global	_open
.type	_open, @function


.align 2
_open:
	trapa	#__NR_open
	rts
	nop
.end
