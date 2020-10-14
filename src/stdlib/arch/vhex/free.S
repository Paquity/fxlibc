#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_free
.type	_free, @function


.align 2
/*
** extern void free(void *ptr)
** Custom syscall which free a block allocated by `malloc', `realloc' or `calloc'.
**
** @note:
** The MMU is used by Casio so we cannot implement brk or skr for technical
** reason (non-continius heap, no shared page, ...), so all memory management
** is performed by the Vhex kernel.
*/
_free:
	trapa	#__NR_proc_heap_free
	rts
	nop
.end
#endif
