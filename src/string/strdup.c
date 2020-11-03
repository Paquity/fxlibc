#include <fxlibc/string.h>
#include <fxlibc/stdlib.h>

/*
** The  strdup()  function  returns a pointer to a new string which is a
** duplicate of the string s. Memory for the new string is obtained with
** malloc(), and can be freed with free().
*/
char *strdup(const char *s)
{
	size_t len;
	void *dump;

	// Check error
	if (s == NULL)
		return (NULL);

	// Check len
	len = strlen(s);
	if (len == 0)
		return (NULL);

	// try to allocate the new area
	dump = malloc(len);
	if (dump == NULL)
		return (NULL);

	// dump the area and return
	memcpy(dump, s, len);
	return (dump);
}

/*
** The strndup() function is similar, but copies at most n bytes. If s is longer
** than n, only n bytes are copied, and a terminating null byte ('\0') is added.
*/
char *strndump(const char *s, size_t n)
{
	size_t len;
	char *dump;

	// Check error
	if (s == NULL)
		return (NULL);

	// Check len
	len = strnlen(s, n);
	if (len == 0)
		return (NULL);

	// try to allocate the new area
	dump = malloc(len);
	if (dump == NULL)
		return (NULL);

	// dump the area, set the null byte and return
	memcpy(dump, s, len);
	dump[len - 1] = '\0';
	return (dump);

}

//TODO: strdupa()
//TODO: strndupa()
