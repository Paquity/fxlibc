#include <fxlibc/string.h>

/*
** The  strcpy() function copies the string pointed to by src, including the
** terminating null byte ('\0'), to the buffer pointed to by dest.
** The strings may  not  overlap,  and  the  destination string dest must be
** large enough to receive the copy. Beware of buffer overruns!
**
** TODO: use quad-word access and/or DMA !
** TODO: look at the DSP ?
*/
char *strcpy(char *dest, char const *src)
{
	size_t i;

	if (src == NULL || dest == NULL)
		return (0);
	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/*
** The strncpy() function is similar, except that at most n bytes of src are
** copied. Warning: If there is no null byte among the first n bytes of src, the
** string placed  in  dest  will  not  be null-terminated.
*/
char *strncpy(char *dest, char const *str, size_t size)
{
	size_t i;

	if (str == NULL || dest == NULL)
		return (0);
	i = -1;
	while (++i < size && str[i] != '\0')
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
