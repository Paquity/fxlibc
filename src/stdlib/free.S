#include <asm/unistd_32.h>
.text
.global	_free
.type	_free, @function


.align 2
/*
** @note: the MMU is used by Casio so we
** can not implement brk or skr because
** of non continuous heap.
*/
_free:
	trapa	#__NR_proc_heap_free
	rts
	nop
.end
