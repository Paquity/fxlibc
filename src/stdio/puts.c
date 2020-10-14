#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
** puts() writes the string s and a trailing newline to stdout.
** FIXME: check last write error !
*/
int puts(const char *s)
{
	size_t size;
	size_t n;

	size = strlen(s);
	n = write(STDOUT_FILENO, s, size);
	write(STDOUT_FILENO, "\n", 1);
	return (-(n == size));
}
