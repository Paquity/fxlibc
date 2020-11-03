#include <fxlibc/string.h>

/*
** The strchr() function returns a pointer to the first occurrence of the
** character c in the strings.
*/
char *strchr(const char *s1, int c)
{
	int i = -1;
	while (s1[++i] != '\0' && s1[i] != c) ;
	return ((s1[i] == '\0') ? NULL : (void *)&s1[i]);
}

/*
** The  strchrnul() function is like strchr() except that if c is not found in
** s, then it returns a pointer to the null byte at the end of s, rather
** than NULL.
*/
char *strchrnul(const char *s1, int c)
{
	int i = -1;
	while (s1[++i] != '\0' && s1[i] != c) ;
	return ((void *)&s1[i]);
}

/*
** The strrchr() function returns a pointer to the last occurrence of the
** character c in the strings.
*/
char *strrchr(const char *s1, int c)
{
	void *saved;

	saved = NULL;
	for (int i = 0; s1[i] != '\0'; i++) {
		if (s1[i] == c)
			saved = (void *)&s1[i];
	}
	return (saved);
}
