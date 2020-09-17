#include <stdio.h>

int snprintf(char *restrict str, size_t size, const char *restrict format, ...)
{
	va_list ap;

	va_start(ap, format);
	size = vsnprintf(str, size, format, ap);
	va_end(ap);
	return (size);
}
