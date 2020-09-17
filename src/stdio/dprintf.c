#include <stdio.h>

int dprintf(int fd, const char *restrict format, ...)
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
