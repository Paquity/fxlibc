#include <asm/unistd_32.h>
.text
.global	_signal
.type	_signal, @function


.align 2
/*
** TODO: doc
*/
_signal:
	trapa	#__NR_signal
	rts
	nop
.end
