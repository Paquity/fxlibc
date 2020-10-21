#include <string.h>

/*
** The strcmp() function compares the two strings s1 and s2. The locale is not
** taken into account (for a locale-aware comparison, see strcoll(3)).
** The comparison is done using unsigned characters.
**
** strcmp() returns an integer indicating the result of the comparison, as follows:
**   * 0, if the s1 and s2 are equal;
**   * a negative value if s1 is less than s2;
**   * a positive value if s1 is greater than s2.
**
** TODO: quad-word access !
*/
int strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
		s1 += 1;
		s2 += 1;
	}
	return (*s1 - *s2);
}

/*
** The strncmp() function is similar, except it compares only the first (at most)
** n bytes of s1 and s2.
**
** TODO: quad-word access !
*/
int strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL || n == 0)
		return (0);
	size_t i = -1;
	while (++i < n - 1 && s1[i] != '\0' && s2[i] != '\0'
	       && s1[i] == s2[i]) ;
	return (s1[i] - s2[i]);
}
