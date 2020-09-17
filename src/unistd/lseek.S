#include <asm/unistd_32.h>
.text
.global	_lseek
.type	_lseek, @function


.align 2
_lseek:
	trapa	#__NR_lseek
	rts
	nop
.end
