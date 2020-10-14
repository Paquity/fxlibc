#ifndef __LIB_SETJMP_H__
# define __LIB_SETJMP_H__

#include <stddef.h>
#include <stdint.h>

/* Get '__jmp_buf' */
#include <bits/setjmp.h>

/* User jmp_buf alias */
typedef struct __jmp_buf jmp_buf[1];


/*
** Store the calling environment in ENV, also saving the signal mask.
** Return 0.
*/
extern int setjmp(jmp_buf env);

/*
** Store the calling environment in ENV, not saving the signal mask.
** Return 0.
*/
extern void longjmp(jmp_buf env, int val);

#endif /*__LIB_SETJMP_H__*/
