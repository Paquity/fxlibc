#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_malloc
.type	_malloc, @function


.align 2
/*
** extern void *malloc(size_t size);
** Allocate SIZE bytes of memory.
**
** @note:
** The MMU is used by Casio so we cannot implement brk or skr for technical
** reason (non-continius heap, no shared page, ...), so all memory management
** is performed by the Vhex kernel.
*/
_malloc:
	trapa	#__NR_proc_heap_alloc
	rts
	nop
.end
#endif
