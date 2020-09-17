#include <asm/unistd_32.h>
.text
.global	_realloc
.type	_realloc, @function

.extern	_malloc
.extern	_free

.align 2
/*
** void *realloc(void ptr, size_t size)
**
** @note: the MMU is used by Casio so we
** can not implement brk or skr because
** of non continuous heap.
*/
_realloc:
	! Check malloc part
	tst 	r4, r4		! if ptr == NULL...
	bf.s	check_free	! ...if not, jump at <check_free>
	mov.l	.malloc, r0	! get malloc() address
	jmp	@r0		! call malloc(size)
	mov 	r5, r4		! (db) send size

	! Check free
check_free:
	tst 	r5, r5		! if size == 0...
	bf.s	call_realloc	! ...if not, jump at <call_realloc>
	mov.l	.free, r0	! get free() address
	sts.l	pr, @-r15	! save pr register
	jmp	@r0		! call free(ptr)
	nop			! (db) nop
	rts			! return...
	xor	r0, r0		! (db) ...NULL


	! Call realloc
call_realloc:
	trapa	#__NR_proc_heap_realloc
	rts
	nop

.align 4
.malloc:	.long _malloc
.free:		.long _free
.end
