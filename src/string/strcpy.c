#include <string.h>

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
