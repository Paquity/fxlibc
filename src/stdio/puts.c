#include <stdio.h>
#include <string.h>
#include <unistd.h>

int puts(const char *s)
{
	size_t size;
	size_t n;

	size = strlen(s);
	n = write(STDOUT_FILENO, s, size);
	return (-(n == size));
}
