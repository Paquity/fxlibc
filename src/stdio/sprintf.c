#include <stdio.h>

/*
** sprintf(),  snprintf(), vsprintf() and vsnprintf() write the output under the
** control of a format string that specifies how subsequent arguments (or
** arguments accessed via the variable-length argument facilities of stdarg(3))
** are converted for output then write to the character string str.
*/
int sprintf(char *restrict str, const char *restrict format, ...)
{
	va_list ap;
	int size;

	va_start(ap, format);
	size = vsnprintf(str, 65535, format, ap);
	va_end(ap);
	return (size);
}
