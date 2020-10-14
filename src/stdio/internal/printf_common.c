#include <stdio.h>

// internal depency
// TODO: update path detection
#include "../src/stdio/internal/printf.h"

//TODO: precision handling
int printf_common(struct printf_opt *opt, const char *restrict format)
{
	extern int printf_get_options(struct printf_opt *opt, const char *restrict format);
	int saved_p;
	int p;

	p = -1;
	opt->counter = 0;
	opt->buffer_cursor = 0;
	while (format[++p] != '\0')
	{
		// Check printable char
		if (format[p] != '%' || format[p + 1] == '%') {
			(*opt->disp_char)(opt, (format[p] != '%') ? format[p] : format[++p]);
			continue;
		}

		// Get options
		saved_p = p;
		p = p + printf_get_options(opt, &format[p + 1]);

		// Check arg validity
		if (((format[p + 1] >= 'a' && format[p + 1] <= 'z') ||
					(format[p + 1] >= 'A' && format[p + 1] <= 'Z')) &&
					action[(format[p + 1] | 0x20) - 'a'] != NULL) {
			(*action[(format[p + 1] | 0x20) - 'a'])(opt, format[p + 1] | 0x20); 
			p = p + 1;
			continue;
		}

		// Default, print the %
		(*opt->disp_char)(opt, '%');
		p = saved_p;
	}
	(*opt->disp_fflush)(opt);
	return (opt->counter);
}
