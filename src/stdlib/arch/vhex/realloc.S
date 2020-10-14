#ifdef __SUPPORT_VHEX_KERNEL
#include <asm/unistd_32.h>
.text
.global	_realloc
.type	_realloc, @function


.align 2
/*
** extern void *realloc(void ptr, size_t size)
**
** @note:
** The MMU is used by Casio so we cannot implement brk or skr for technical
** reason (non-continius heap, no shared page, ...), so all memory management
** is performed by the Vhex kernel.
*/
_realloc:
	! Check if the PTR is NULL
	! In this case, realloc() work like malloc(), so lets call it
	tst 	r4, r4
	bf	check_free
	mov 	r5, r4
	trapa	#__NR_proc_heap_alloc
	rts
	nop

	! Check is the size is NULL
	! In this case, realloc() work like free(), so lets call it
	! then return NULL pointer
check_free:
	tst 	r5, r5
	bf	call_realloc
	trapa	#__NR_proc_heap_free
	rts
	xor	r0, r0

	! Call realloc
call_realloc:
	trapa	#__NR_proc_heap_realloc
	rts
	nop
.end
#endif
