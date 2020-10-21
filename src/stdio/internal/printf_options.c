#include <stdio.h>

// internal depency
// TODO: update path detection
#include "../src/stdio/internal/printf.h"

static int get_flags(struct printf_opt *opt, const char *restrict format)
{
	int i;

	i = -1;
	opt->flags.diez = 0;
	opt->flags.zero = 0;
	opt->flags.minus = 0;
	opt->flags.space = 0;
	opt->flags.plus = 0;
	while (format[++i] != '\0') {
		switch (format[i]) {
		case '#':
			opt->flags.diez = 1;
			break;
		case '0':
			opt->flags.zero = 1;
			break;
		case '-':
			opt->flags.minus = 1;
			break;
		case ' ':
			opt->flags.space = 1;
			break;
		case '+':
			opt->flags.plus = 1;
			break;
		default:
			return (i);
		}
	}
	return (i);
}

static int get_width(struct printf_opt *opt, const char *restrict format)
{
	// Check dynamic width
	if (format[0] == '*') {
		opt->width = va_arg(opt->ap, int);
		return (1);
	}

	// Check error
	int i = -1;
	opt->width = 0;
	if (format[0] == '0')
		return (0);

	// Get static width
	while (format[++i] >= '0' && format[i] <= '9')
		opt->width = (opt->width * 10) + (format[i] - '0');
	return (i);
}

static int get_precision(struct printf_opt *opt, const char *restrict format)
{
	// Check if precision is specified
	if (format[0] != '.')
		return (0);

	// Check dynamic precision
	if (format[1] == '*') {
		opt->precision = va_arg(opt->ap, int);
		return (2);
	}

	// Get static precision
	int i = 0;
	opt->precision = 0;
	while (format[++i] >= '0' && format[i] <= '9')
		opt->precision = (opt->precision * 10) + (format[i] - '0');

	// Check default precision
	if (i == 0)
		opt->precision = 1;
	return (i);
}

static int get_lenght(struct printf_opt *opt, const char *restrict format)
{
	opt->lenght = -1;
	switch (format[0]) {
	case 'h':
		opt->lenght = (format[1] == 'h') ? 1 : 0;
		break;
	case 'l':
		opt->lenght = (format[1] == 'l') ? 3 : 2;
		break;
	case 'j':
		opt->lenght = 4;
		break;
	case 'z':
		opt->lenght = 5;
		break;
	case 't':
		opt->lenght = 6;
		break;
	default:
		return (0);
	}
	return ((opt->lenght == 1 || opt->lenght == 3) ? 2 : 1);
}

int printf_get_options(struct printf_opt *opt, const char *restrict format)
{
	int i;

	// Wipe internal format infos
	opt->sign = '\0';
	opt->base[0] = '\0';
	opt->base[1] = '\0';

	// Get generals opetions
	i = get_flags(opt, &format[0]);
	i += get_width(opt, &format[i]);
	i += get_precision(opt, &format[i]);
	i += get_lenght(opt, &format[i]);

	// Check upper case actions
	opt->uppercase = (format[i] == 'X') ? 1 : 0;
	return (i);
}
