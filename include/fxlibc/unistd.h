#ifndef __LIB_UNISTD_H__
# define __LIB_UNISTD_H__

#include <stddef.h>
#include <stdint.h>

#include <fxlibc/sys/types.h>

//---
// Process part
///---
/* Get the process ID of the calling process. */
extern pid_t getpid(void);

/* Get the process group ID of the calling process. */
extern pid_t getpgid(void);

/* Get the process ID of the calling process's parent. */
extern pid_t getppid(void);

/*
** Set the process group ID of the process matching PID to PGID.
** If PID is zero, the current process's process group ID is set.
** If PGID is zero, the process ID of the process is used.
*/
extern int setpgid(pid_t __pid, pid_t __pgid);

// CUSTOM syscall for Vhex (fork() + exeve()) !
//TODO: move me !!
extern pid_t fork_execve(const char *pathname, char **argv, char **envp);

//---
// File part
//---
/* Standard file descriptors. */
#define STDIN_FILENO	0	/* Standard input. */
#define STDOUT_FILENO	1	/* Standard output. */
#define STDERR_FILENO	2	/* Standard error output. */

/*
** Write N bytes of BUF to FD.
** Return the number written, or -1.
*/
extern ssize_t write(int __fd, const void *__buf, size_t __nbytes);

/*
** Read NBYTES into BUF from FD.
** Return the number read, -1 for errors or 0 for EOF.
*/
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);

/*
** Read NBYTES into BUF from FD at the given position OFFSET without
** changing the file pointer.
** Return the number read, -1 for errors or 0 for EOF.
*/
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes, off_t __offset);

/*
** Write N bytes of BUF to FD at the given position OFFSET without
** changing the file pointer.
** Return the number written, or -1.
*/
extern ssize_t pwrite (int __fd, const void *__buf, size_t __n, off_t __offset);

/* Values for the WHENCE argument to lseek.  */
#define SEEK_SET       0       /* Seek from beginning of file.  */
#define SEEK_CUR       1       /* Seek from current position.  */
#define SEEK_END       2       /* Seek from end of file.  */

/*
** Move FD's file position to OFFSET bytes from the beginning of the file
** (if WHENCE is SEEK_SET), the current position (if WHENCE is SEEK_CUR),
** or the end of the file (if WHENCE is SEEK_END).
** Return the new file position.
*/
extern off_t lseek (int __fd, off_t __offset, int __whence);

/* Close the file descriptor FD */
extern int close(int __fd);

//---
// System part
//---
/*
** Get the `_PC_*' symbols for the NAME argument to `pathconf' and `fpathconf';
** the `_SC_*' symbols for the NAME argument to `sysconf'; and the `_CS_*'
** symbols for the NAME argument to `confstr'.
*/
#include <fxlibc/bits/confname.h>

/* Get the value of the system variable NAME. */
extern long int sysconf(int __name);

#endif /*__LIB_UNISTD_H__*/
