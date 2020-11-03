#ifndef __ASM_CASIO_TRAPA_H__
# define __ASM_CASIO_TRAPA_H__

/*
** Normally the SH3/SH4 processor provide a "trapa" instruction which allow
** tipping between userland and kernel. But Casio's don't use this method
** (this is why we are always in "privilegied mode" and we can do whatever
** we whant) but use custom calling convention to access the syscall call.
**
** The convention whant that the user jump into the syscall trampoline code
** located at 0x80010070 for fx9860g and 0x80020070 for fxcg20/50.
*/
#ifdef __SUPPORT_CASIO_ABI_FX9860G
# define casio_trapa(id)		\
	mov.l	syscall_table, r2	;\
	mov.l	syscall_id, r0		;\
	jmp	@r2			;\
	nop				;\
.align 4				;\
syscall_table:	.long 0x80010070	;\
syscall_id:	.long id
#endif

#ifdef __SUPPORT_CASIO_ABI_FXCG50
# define casio_trapa(id)		\
	mov.l	syscall_table, r2	;\
	mov.l	syscall_id, r0		;\
	jmp	@r2			;\
	nop				;\
.align 4				;\
syscall_table:	.long 0x80020070	;\
syscall_id:	.long id
#endif

#endif /*__ASM__CASIO_TRAPA_H__*/
