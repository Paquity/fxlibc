#include <asm/unistd_32.h>
.text
.global	_read
.type	_read, @function


.align 2
_read:
	trapa	#__NR_read
	rts
	nop
.end
