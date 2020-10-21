#include <string.h>

/*
** The  strlen() function calculates the length of the string pointed to by s,
** excluding the termi‐nating null byte ('\0').
**
** TODO: use quad-word access !
*/
size_t strlen(char const *str)
{
	size_t i;

	if (str == NULL)
		return (0);
	i = -1;
	while (str[++i] != '\0') ;
	return (i);
}

/*
** The strnlen() function returns the number of bytes in the string pointed to
** by s, excluding the terminating null byte ('\0'), but at most maxlen.
** In doing this, strnlen() looks  only  at  the first maxlen characters in the
** string pointed to by s and never beyond s+maxlen.
**
** TODO: use quad-word access !
*/
size_t strnlen(char const *str, size_t maxlen)
{
	size_t i;

	if (str == NULL)
		return (0);
	i = -1;
	while (str[++i] != '\0' && (size_t)i < maxlen) ;
	return (i);
}
