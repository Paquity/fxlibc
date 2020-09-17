#include <asm/unistd_32.h>
.text
.global	_close
.type	_close, @function


.align 2
_close:
	trapa	#__NR_close
	rts
	nop
.end
