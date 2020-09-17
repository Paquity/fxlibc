#include <string.h>

int strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1 += 1;
		s2 += 1;
	}
	return (*s1 - *s2);
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL || n == 0)
		return (0);
	size_t i = -1;
	while (++i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]);
	return (s1[i] - s2[i]);
}
