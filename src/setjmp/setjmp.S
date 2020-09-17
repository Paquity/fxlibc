.text
.global	_setjmp
.type	_setjmp, @function

.align 2
/*
** int setjmp(jmp_buf env)
** @note: TODO
*/
_setjmp:
	! block interrupt
	stc	sr, r1
	mov	r1, r3
	mov	#0x10, r2
	shll8	r2
	shll16	r2
	or	r2, r1
	ldc 	r1, sr

	! save current context
	! @note: r3 is the saved SR regsiter
	add	#52, r4
	sts.l	pr, @-r4
	sts.l	mach, @-r4
	sts.l	macl, @-r4
	stc.l	gbr, @-r4
	mov.l	r15, @-r4
	mov.l	r14, @-r4
	mov.l	r13, @-r4
	mov.l	r12, @-r4
	mov.l	r11, @-r4
	mov.l	r10, @-r4
	mov.l	r9, @-r4
	mov.l	r8, @-r4
	mov.l	r3, @-r4

	! restore sr
	ldc	r3, sr

	! return
	rts
	mov	#0, r0

