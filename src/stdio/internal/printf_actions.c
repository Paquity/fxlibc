#include <stdio.h>

// internal depency
// TODO: update path detection
#include "../src/stdio/internal/printf.h"

// Define all actions
static void action_str(struct printf_opt *op, char n);
static void action_ptr(struct printf_opt *op, char n);
static void action_int(struct printf_opt *op, char n);
static void action_uint(struct printf_opt *op, char n);
static void action_char(struct printf_opt *op, char n);

// Define all actions which can be used
void (*action[26])(struct printf_opt *opt, char n) = {
	NULL,		NULL,		action_char,	action_int,
	NULL,		NULL,		NULL,		NULL,
	action_int,	NULL,		NULL,		NULL,
	NULL,		NULL,		action_uint,	action_ptr,
	NULL,		NULL,		action_str,	NULL,
	action_uint,	NULL,		NULL,		action_uint,
	NULL,		NULL,
};


//---
//      Disp part
//---
static void base_to_str(struct printf_opt *opt, uint32_t num, int base,
			int digits)
{
	char *hexa = "0123456789abcdef";
	if (opt->uppercase == 1)
		hexa = "0123456789ABCDEF";

	opt->digits = 0;
	while (num != 0 || opt->digits < digits) {
		opt->format[opt->digits++] = hexa[num % base];
		num = num / base;
	}
}

static void disp_format(struct printf_opt *opt)
{
	// display pre symbols
	if (opt->sign != '\0')
		(*opt->disp_char)(opt, opt->sign);
	if (opt->base[0] != '\0')
		(*opt->disp_char)(opt, opt->base[0]);
	if (opt->base[1] != '\0')
		(*opt->disp_char)(opt, opt->base[1]);

	// padding
	if (opt->flags.minus == 1 && opt->width > opt->digits) {
		int total = opt->digits + (opt->sign != '\0') +
			(opt->base[0] != '\0') + (opt->base[1] != '\0');
		total = opt->width - total;
		while (--total >= 0)
			(*opt->disp_char)(opt,
					(opt->flags.zero == 1) ? '0' : ' ');

	}

	// Display number
	int saved_digits = opt->digits;
	while (--opt->digits >= 0)
		(*opt->disp_char)(opt, opt->format[opt->digits]);

	// padding
	if (opt->flags.minus == 0 && opt->width > saved_digits) {
		int total = saved_digits + (opt->sign != '\0') +
			(opt->base[0] != '\0') + (opt->base[1] != '\0');
		total = opt->width - total;
		while (--total >= 0)
			(*opt->disp_char)(opt, ' ');
	}
}


//---
//      Args part
//---
static uint32_t get_arg_i(struct printf_opt *opt)
{
	switch (opt->lenght) {
	case 0:
		return ((signed char)va_arg(opt->ap, int));
	case 1:
		return ((short int)va_arg(opt->ap, int));
	case 2:
		return (va_arg(opt->ap, long int));
	case 3:
		return (va_arg(opt->ap, long long int));
	case 4:
		return (va_arg(opt->ap, intmax_t));
	case 5:
		return (va_arg(opt->ap, size_t));
	case 6:
		return (va_arg(opt->ap, ptrdiff_t));
	}
	return (va_arg(opt->ap, int));
}

static uint32_t get_arg_u(struct printf_opt *opt)
{
	switch (opt->lenght) {
	case 0:
		return ((unsigned char)va_arg(opt->ap, int));
	case 1:
		return ((unsigned short int)va_arg(opt->ap, int));
	case 2:
		return (va_arg(opt->ap, unsigned long int));
	case 3:
		return (va_arg(opt->ap, unsigned long long int));
	case 4:
		return (va_arg(opt->ap, intmax_t));
	case 5:
		return (va_arg(opt->ap, size_t));
	case 6:
		return (va_arg(opt->ap, ptrdiff_t));
	}
	return (va_arg(opt->ap, unsigned int));
}


//---
//      Actions part.
//---
static void action_str(struct printf_opt *opt, char n)
{
	const char *str;

	(void)n;
	str = va_arg(opt->ap, const char *);
	while (*str != '\0')
		(*opt->disp_char)(opt, *(str++));
}

static void action_char(struct printf_opt *opt, char n)
{
	n = (char)va_arg(opt->ap, int);
	(*opt->disp_char)(opt, n);
}

static void action_ptr(struct printf_opt *opt, char n)
{
	(void)n;
	opt->sign = '@';
	opt->base[0] = '0';
	opt->base[1] = 'x';
	base_to_str(opt, (uintptr_t)va_arg(opt->ap, void*), 16, 8);
	disp_format(opt);
}

static void action_int(struct printf_opt *opt, char n)
{
	int64_t num;

	// Get data and check negative value
	// FIXME: max negative value can not be reversed
	(void)n;
	num = get_arg_i(opt);
	if (num < 0) {
		opt->sign = '-';
		num = -num;
	} else if (opt->flags.space == 1 || opt->flags.plus == 1) {
		opt->sign = (opt->flags.plus == 1) ? '+' : ' ';
	}

	// Generate / display number
	base_to_str(opt, num, 10, 1);
	disp_format(opt);
}

static void action_uint(struct printf_opt *opt, char n)
{
	uint32_t num;
	int base;

	// Get appropriate base
	switch (n) {
	case 'o':
		base = 8;
		break;
	case 'x':
		base = 16;
		break;
	default:
		base = 10;
		break;
	}

	// Display extra symbols if needed
	if (opt->flags.diez == 1) {
		if (n == 'o') {
			opt->base[0] = '0';
		} else if (n == 'x') {
			opt->base[0] = '0';
			opt->base[1] = (opt->uppercase == 1) ? 'X' : 'x';
		}
	}

	// Get number
	num = get_arg_u(opt);

	// Generate / display number
	base_to_str(opt, num, base, 1);
	disp_format(opt);
}
