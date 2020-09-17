.text
.global	___thread_atomic_start
.global	___thread_atomic_stop

.type	___thread_atomic_start, @function
.type	___thread_atomic_stop, @function

.align 2
// Save the current SR register and set the SR.BIT bit up (start atomic operations)
// @note: return the saved SR register (if has been saved), 0xffffffff otherwise.
___thread_atomic_start:
	! Check if the calculator is currently
	! into an atomic operation and update
	! atomic counter.
	mov.l	atomic_counter, r1	! r1 = atomic counter address
	mov.l	@r1, r2			! r2 = atomic counter data
	tst	r2, r2			! if atomic counter == 0...
	add	#1, r2			! update atomic counter data
	mov.l	r2, @r1			! update atomic counter.
	bf.s	atomic_start_exit	! ...if not, jump <atomic_start_exit>
	mov	#-1, r0			! (db) return 0xffffffff

	! Block interrupt if needed.
	stc	sr, r1			! get SR register.
	mov	r1, r0			! save current SR register.
	mov.l	bl_mask, r2		! get SR.BL mask.
	or	r2, r1			! set SR.BL = 1 and SR.IMASK = 0b1111.
	ldc	r1, sr			! update SR register.

	! Save "old" SR register.
	mov.l	sr_save, r1		! r1 = sr_save address
	mov.l	r0, @r1			! save "old" SR register data.

atomic_start_exit:
	rts				! exit.
	nop				! (db) nop.

// Restore the saved SR register
// @note: return the restored SR register or -1 otherwise.
___thread_atomic_stop:

	! Check if the calculator is currently
	! into an atomic operation and update
	! atomic counter if pssible.
	mov.l	atomic_counter, r1	! r1 = atomic counter address
	mov.l	@r1, r0			! r0 = atomic counter data
	tst	r0, r0			! if atomic counter == 0...
	bt	atomic_end_error	! ...if yes, jump at <atomic_end_error>
	cmp/eq	#1, r0			! if atomic counter == 1...
	add	#-1, r0			! update atomic counter data
	mov.l	r0, @r1			! update atomic counter
	bf	atomic_end_error	! ...if not, jump at <atomic_end_error>

	! Restore saved SR register data.
	mov.l	sr_save, r1		! get sr_save address
	mov.l	@r1, r0			! r0 = "old" SR register data
	ldc	r0, sr			! restore SR register.
	bra	atomic_end_exit		! return the resotred SR register.
	nop				! (db) nop

atomic_end_error:
	mov	#-1, r0			! return 0xffffffff

atomic_end_exit:
	rts				! exit.
	nop				! (db) nop.

.align 4
bl_mask:		.long 0x100000f0
sr_save:		.long ___thread_atomic_sr_save
atomic_counter:		.long ___thread_atomic_counter




##---
##	Global part.
##---
.data
.global	___thread_atomic_sr_save
.global ___thread_atomic_counter

.type	___thread_atomic_sr_save, @object
.type	___thread_atomic_counter, @object

.align 4
___thread_atomic_sr_save:	.long 0x00000000
___thread_atomic_counter:	.long 0x00000000
