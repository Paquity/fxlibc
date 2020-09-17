#include <asm/unistd_32.h>
.text
.global	_malloc
.type	_malloc, @function


.align 2
/*
** @note: We can not implement brk or skr
** because the MMU is used by Casio.
*/
_malloc:
	trapa	#__NR_proc_heap_alloc
	rts
	nop
.end
