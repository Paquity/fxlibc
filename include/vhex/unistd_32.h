#ifndef __ASM_UNISTD32_VHEX_H__
# define __ASM_UNISTD32_VHEX_H__

// Define the number of syscall
#define __NR_MAX		21

// Kernel Test
#define __NR_test_syscall	0

// Process
#define __NR_exit 		1
#define __NR_fork_execve 	2 // (custom)
#define __NR_waitpid 		3
#define __NR_wait 		4
#define __NR_getpid 		5
#define __NR_getppid 		6
#define __NR_getpgid 		7
#define __NR_setpgid 		8

// Signal
#define __NR_signal 		9
#define __NR_sigreturn 		10
#define __NR_sigaction 		11
#define __NR_kill 		12
#define __NR_sigprogmask	13
#define __NR_sigpending		14
#define __NR_sigaltstack	15

// VFS
#define __NR_read 		16
#define __NR_write		17
#define __NR_open 		18
#define __NR_close 		19
#define __NR_lseek 		20
#define __NR_pread 		21
#define __NR_pwrite		22

// Memory
#define __NR_mmap		23
#define __NR_munmap		24
#define __NR_proc_heap_alloc	25 // (custom)
#define __NR_proc_heap_free	26 // (custom)
#define __NR_proc_heap_realloc	27 // (custom)

#endif /*__ASM_UNISTD32_VHEX_H__*/
