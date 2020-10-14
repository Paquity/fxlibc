#include <stdio.h>
#include <unistd.h>

/*
** printf() write the output under the control of a format string that specifies
** how subsequent arguments (or arguments accessed via the variable-length
** argument facilities of stdarg(3)) are converted for output then write to
** the STDOUT.
*/
int printf(const char *restrict format, ...)
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (ret);
}
