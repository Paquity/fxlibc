#include <string.h>

//TODO: asm ?
char *strchr(const char *s1, int c)
{
	int i = -1;
	while (s1[++i] != '\0' && s1[i] != c);
	return ((s1[i] == '\0') ? NULL : (void*)&s1[i]);
}

//TODO: asm ?
char *strchrnul(const char *s1, int c)
{
	int i = -1;
	while (s1[++i] != '\0' && s1[i] != c);
	return ((void*)&s1[i]);
}

//TODO asm ?
char *strrchr(const char *s1, int c)
{
	void *saved;

	saved = NULL;
	for (int i = 0 ; s1[i] != '\0' ; i++)
	{
		if (s1[i] == c)
			saved = (void *)&s1[i];
	}
	return (saved);
}
