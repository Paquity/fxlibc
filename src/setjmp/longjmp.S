.text
.global	_longjmp
.type	_longjmp, @function


.align 2
/*
** void longjmp(jmp_buf env, int val)
** Store the calling environment in ENV, not saving the signal mask.
** Return 0.
*/
_longjmp:
	! save the context into unbankable register
	mov	r4, r8

	! check the returned value validity
	tst	r5, r5
	bf/s	int_block
	mov	r5, r9
	mov	#1, r9

	! block interrupt
int_block:
	stc	sr, r1
	mov	#0x10, r2
	shll8	r2
	shll16	r2
	or	r2, r1
	ldc 	r1, sr

context_switch:
	! load the old SR regsiter first to force register bank switch
	! (if needed) then move the context and the returned value into
	! non-saved (by the setjmp context) registers.
	ldc.l	@r8+, sr
	mov	r8, r4
	mov	r9, r0

	! restore all old registers
	mov.l	@r4+, r8
	mov.l	@r4+, r9
	mov.l	@r4+, r10
	mov.l	@r4+, r11
	mov.l	@r4+, r12
	mov.l	@r4+, r13
	mov.l	@r4+, r14
	mov.l	@r4+, r15
	ldc.l	@r4+, gbr
	lds.l	@r4+, macl
	lds.l	@r4+, mach
	lds.l	@r4+, pr

	! return to the old place
	rts
	nop
