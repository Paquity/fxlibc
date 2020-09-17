#include <stdio.h>

int vsprintf(char *restrict str, const char *restrict format, va_list ap)
{
	return (vsnprintf(str, 65535, format, ap));	
}
