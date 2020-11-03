#ifndef __SYSCALL_H__
# define __SYSCALL_H__

/*
** This file should list the numbers of the system calls the system knows.
** But instead of duplicating this we use the information available
** from the kernel sources.
*/
#include <fxlibc/asm/unistd.h>

/*
** The Linux kernel header file defines macros __NR_*, but some
** programs expect the traditional form SYS_*.  <bits/syscall.h>
** defines SYS_* macros for __NR_* macros of known names.
*/
#include <fxlibc/bits/syscall.h>

#endif
