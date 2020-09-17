#include <asm/unistd_32.h>
.text
.global	_kill
.type	_kill, @function


.align 2
/*
** TODO: doc
*/
_kill:
	trapa	#__NR_kill
	rts
	nop
.end
