#ifndef __BITS_SETJMP_H__
# define __BITS_SETJMP_H__

#include <stddef.h>
#include <stdint.h>

/*
** Custom(?) jmp_buf struct
** @note: save only r8 ~ r15 and SR / PC registers
** The SR register is saved first because the longjump can be involved with
** different register bank. So to avoid this, it's more simple to restore the
** saved SR first then restore all register (see <src/setjmp/longjmp.S>)
**
** TODO: save process signal mask ?
*/
struct __jmp_buf
{
	uint32_t sr;
	uint32_t reg[8];
	uint32_t gbr;
	uint32_t macl;
	uint32_t mach;
	uint32_t pr;
};

#endif /*__BITS_SETJMP_H__*/
