#include <fxlibc/stdio.h>
#include <fxlibc/unistd.h>

int putchar(int c)
{
	char n;

	n = (char)c;
	write(STDOUT_FILENO, &n, 1);
	return (n);
}
