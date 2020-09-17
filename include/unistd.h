#ifndef __LIB_UNISTD_H__
# define __LIB_UNISTD_H__

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

// TODO: move me
#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

//TODO: move me
#define _SC_PAGE_SIZE	0
#define _SC_PAGESIZE	_SC_PAGE_SIZE


// Process part
extern pid_t getpid(void);
extern pid_t getpgid(void);
extern pid_t getppid(void);
extern int setpgid(pid_t pid, pid_t pgid);

// CUSTOM function (fork() + exeve()) !
extern pid_t fork_execve(const char *pathname, char **argv, char **envp);

// File part
extern ssize_t write(int fd, const void *buf, size_t count);
extern ssize_t read(int fd, void *buf, size_t count);
extern off_t lseek(int fd, off_t offset, int whence);
extern int close(int fd);

// System part
extern long sysconf(int name);

#endif /*__LIB_UNISTD_H__*/
