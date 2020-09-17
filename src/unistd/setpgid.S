#include <asm/unistd_32.h>
.text
.global	_setpgid
.type	_setpgid, @function


.align 2
_setpgid:
	trapa	#__NR_setpgid
	rts
	nop
.end
