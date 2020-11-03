#include <fxlibc/stdio.h>

/*
** The functions vsprintf() are equivalent to the sprintf() except that  they
** are called with a va_list instead of a variable number of arguments. These
** functions do not call the va_end macro. Because they invoke the va_arg macro,
** the value of ap is undefined after the call.
*/
int vsprintf(char *restrict str, const char *restrict format, va_list ap)
{
	return (vsnprintf(str, 65535, format, ap));
}
