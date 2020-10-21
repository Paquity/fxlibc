#include <string.h>

/*
** The  strcat()  function  appends  the src string to the dest string,
** overwriting the terminating null byte ('\0') at the end of dest, and then
** adds a terminating null byte. The strings may not overlap, and the dest
** string must have enough space for the result. If dest is not large enough,
** program behavior is unpredictable; buffer overruns are a favorite avenue for
** attacking secure programs.
**
** TODO: use the DMA !
** TODO: look at the DSP ?
*/
char *strcat(char *dest, char const *src)
{
	size_t i;
	size_t start;

	if (src == NULL || dest == NULL)
		return (0);
	i = -1;
	start = -1;
	while (dest[++start] != '\0') ;
	while (src[++i] != '\0')
		dest[start + i] = src[i];
	dest[i + start] = '\0';
	return (dest);
}

/*
** The strncat() function is similar, except that:
**   *  it will use at most n bytes from src; and
**   *  src does not need to be null-terminated if it contains n or more bytes.
**
** As with strcat(), the resulting string in dest is always null-terminated.
**
** If src contains n or more bytes, strncat() writes n+1 bytes to dest (n from
** src plus the terminating null byte). Therefore, the size of dest must be at
** least strlen(dest)+n+1.
*/
char *strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}
