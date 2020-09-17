#include <string.h>
#include <stdlib.h>

char *strdup(const char *s)
{
	size_t len;
	void *dump;

	// Check error
	if (s == NULL)
		return (NULL);

	// Check len
	len = strlen(s);
	if (len  == 0)
		return (NULL);

	// Dump string and return
	dump = malloc(len);
	memcpy(dump, s, len);
	return (dump);
}
