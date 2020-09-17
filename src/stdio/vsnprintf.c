#include <stdio.h>

static void disp_char(struct printf_opt *opt, char n)
{
	// Check write possibility
	if (opt->buffer_cursor < opt->str_size - 1) {
		opt->str[opt->buffer_cursor] = n;
		opt->buffer_cursor = opt->buffer_cursor + 1;
	}
}

static void disp_fflush(struct printf_opt *opt)
{
	opt->str[opt->buffer_cursor] = '\0';
}

int vsnprintf(char *restrict str, size_t size, const char *restrict format, va_list ap)
{
	extern int printf_common(struct printf_opt *opt, const char *restrict format);
	struct printf_opt opt;

	opt.str = str;
	opt.str_size = size;
	opt.disp_char = &disp_char;
	opt.disp_fflush = &disp_fflush;
	va_copy(opt.ap, ap);
	return (printf_common(&opt, format) + 1);
}

