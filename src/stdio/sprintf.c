#include <stdio.h>

int sprintf(char *restrict str, const char *restrict format, ...)
{
	va_list ap;
	int size;

	va_start(ap, format);
	size = vsnprintf(str, 65535, format, ap);
	va_end(ap);
	return (size);
}
