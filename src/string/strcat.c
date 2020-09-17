#include <string.h>

char *strcat(char *dest, char const *src)
{
	size_t i;
	size_t start;

	if (src == NULL || dest == NULL)
		return (0);
	i = -1;
	start = -1;
	while (dest[++start] != '\0');
	while (src[++i] != '\0')
		dest[start + i] = src[i];
	dest[i + start] = '\0';
	return (dest);
}
