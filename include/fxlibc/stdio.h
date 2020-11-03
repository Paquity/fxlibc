#ifndef __LIB_STDIO_H__
# define __LIB_STDIO_H__

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

/* *printf() familly - formatted output conversion. */
extern int printf(const char *restrict format, ...);
extern int dprintf(int fd, const char *restrict format, ...);
extern int sprintf(char *restrict str, const char *restrict format, ...);
extern int snprintf(char *restrict str, size_t size, const char *restrict format, ...);
extern int vdprintf(int fd, const char *restrict format, va_list ap);
extern int vsprintf(char *restrict str, const char *restrict format, va_list ap);
extern int vsnprintf(char *restrict str, size_t size, const char *restrict format, va_list ap);

/* putx() - display char / string */
extern int putchar(int c);
extern int puts(const char *s);

#endif /*__LIB_STDIO_H__*/
