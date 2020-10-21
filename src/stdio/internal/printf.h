#ifndef _SRC_STDIO_INTERNAL_PRINTF_H__
#define _SRC_STDIO_INTERNAL_PRINTF_H__

#include <stddef.h>
#include <stdint.h>

//---
// Internal printf() part
//---
#define PRINTF_INTERNAL_BUFFER_SIZE 32

// internal structure used by any printf function familly
struct printf_opt
{
	// Internal buffer to avoid syscall flux
	char buffer[PRINTF_INTERNAL_BUFFER_SIZE];
	size_t buffer_cursor;

	// Common part
	int counter;
	va_list ap;

	// *dprintf part
	int fd;

	// *sprintf part
	char *str;
	size_t str_size;

	// For string / fd common support
	void (*disp_char)(struct printf_opt *opt, char n);
	void (*disp_fflush)(struct printf_opt *opt);

	// Printf-options
	struct {
		uint8_t diez 	: 1;
		uint8_t zero 	: 1;
		uint8_t minus	: 1;
		uint8_t space 	: 1;
		uint8_t plus 	: 1;
		uint8_t const	: 3;
	} flags;
	int width;
	int precision;
	int uppercase;
	int lenght;

	// Internal format management.
	char sign;
	char base[2];
	char format[32];
	int digits;
};

// Internal symbols used to define all actions possibility
extern void (*action[26])(struct printf_opt *opt, char n);

#endif /*_SRC_STDIO_INTERNAL_PRINTF_H__*/
