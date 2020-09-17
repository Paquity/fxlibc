#include <asm/unistd_32.h>
.text
.global	_write
.type	_write, @function


.align 2
_write:
	trapa	#__NR_write
	rts
	nop
.end
