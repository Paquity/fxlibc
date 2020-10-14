#include <stdio.h>
#include <unistd.h>

// internal depency
// TODO: update path detection
#include "../src/stdio/internal/printf.h"

// FIXME:
// if the writte syscall do not return the same
// number of bytes that requested, stop the function !
static void disp_fflush(struct printf_opt *opt)
{
	if (opt->buffer_cursor != 0) {
		opt->counter += write(opt->fd, opt->buffer, opt->buffer_cursor);
		opt->buffer_cursor = 0;
	}
}

static void disp_char(struct printf_opt *opt, char n)
{
	// Check if we should force flush the internal buffer
	if (opt->buffer_cursor >= PRINTF_INTERNAL_BUFFER_SIZE)
		disp_fflush(opt);

	// Save char
	opt->buffer[opt->buffer_cursor++] = n;
}

int vdprintf(int fd, const char *restrict format, va_list ap)
{
	extern int printf_common(struct printf_opt *opt, const char *restrict format);
	struct printf_opt opt;

	opt.fd = fd;
	opt.disp_char = &disp_char;
	opt.disp_fflush = &disp_fflush;
	va_copy(opt.ap, ap);
	return (printf_common(&opt, format));
}
