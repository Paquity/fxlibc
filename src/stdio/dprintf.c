#include <fxlibc/stdio.h>

/*
** The function dprintf() is the same as fprintf() except that it outputs to a
** file descriptor, fd, instead of to a stdio stream.
*/
int dprintf(int fd, const char *restrict format, ...)
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
