#include <asm/unistd_32.h>
.text
.global	_waitpid
.type	_waitpid, @function


.align 2
_waitpid:
	trapa	#__NR_waitpid
	rts
	nop
.end
