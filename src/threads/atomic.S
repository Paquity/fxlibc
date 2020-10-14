.text
.global	___thread_atomic_start
.global	___thread_atomic_stop

.type	___thread_atomic_start, @function
.type	___thread_atomic_stop, @function

.align 2
/*
** extern uint32_t __thread_atomic_start(void)
** Save the current SR register and set the SR.BIT bit up to start an atomic
** context (interrupt is blocked).
** Return the saved SR register (only if the we enter into an atomic context),
** 0xffffffff otherwise.
*/
___thread_atomic_start:
	! Check if the user is currently into an atomic operation
	! and update atomic counter.
	mov.l	atomic_counter, r1
	mov.l	@r1, r2
	tst	r2, r2
	add	#1, r2
	mov.l	r2, @r1
	bf.s	atomic_start_exit
	mov	#-1, r0

	! Block interrupt if needed.
	stc	sr, r1
	mov	r1, r0
	mov.l	bl_mask, r2
	or	r2, r1
	ldc	r1, sr

	! Save "old" SR register.
	mov.l	sr_save, r1
	mov.l	r0, @r1

atomic_start_exit:
	rts
	nop

/*
** extern uint32_t __thread_atomic_stop(void)
** Decreate the internal "atomic context counter" and if the counter is 0,
** restore the saved SR register status.
** Return the restored SR register (if restored) or -1 otherwise.
*/
___thread_atomic_stop:

	! Check if the device is currently into an atomic operation
	! and update atomic counter and, if needed, restore the SR
	! regsiter
	mov.l	atomic_counter, r1
	mov.l	@r1, r0
	tst	r0, r0
	bt	atomic_end_error
	cmp/eq	#1, r0
	add	#-1, r0
	mov.l	r0, @r1
	bf	atomic_end_error

	! Restore saved SR register data.
	mov.l	sr_save, r1
	mov.l	@r1, r0
	ldc	r0, sr
	bra	atomic_end_exit
	nop

atomic_end_error:
	mov	#-1, r0

atomic_end_exit:
	rts
	nop

.align 4
bl_mask:		.long 0x100000f0
sr_save:		.long ___thread_atomic_sr_save
atomic_counter:		.long ___thread_atomic_counter



##---
## Global part.
##---
.data
.global	___thread_atomic_sr_save
.global ___thread_atomic_counter

.type	___thread_atomic_sr_save, @object
.type	___thread_atomic_counter, @object

.align 4
___thread_atomic_sr_save:	.long 0x00000000
___thread_atomic_counter:	.long 0x00000000
