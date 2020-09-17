#ifndef __LIB_SETJMP_H__
# define __LIB_SETJMP_H__

#include <stddef.h>
#include <stdint.h>

// Real jmp_buf struct
// @note: save only r8 ~ r15 and SR / PC registers
// The SR register is saved first because the longjump can be involved with
// differentregister bank. So to avoid this it's more simple to restore the
// saved SR first then restore all register (see <lib/libc/setjmp/longjmp.S>)
struct __jmp_buf
{
	uint32_t sr;
	uint32_t reg[8];
	uint32_t gbr;
	uint32_t macl;
	uint32_t mach;
	uint32_t pr;
};

// User jmp_buf alias
typedef struct __jmp_buf jmp_buf[1];


// Functions
extern int setjmp(jmp_buf env);
extern void longjmp(jmp_buf env, int val);

#endif /*__LIB_SETJMP_H__*/
