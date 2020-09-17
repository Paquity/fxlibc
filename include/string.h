#ifndef __STRING_H__
# define __STRING_H__

#include <stdint.h>
#include <stddef.h>

/* memset() - fill memory with a constant byte. */
extern void *memset(void *s, int c, size_t n);
extern void *memcpy(void *dest, const void *src, size_t n);

/* strcat() - concatenate two string */
extern char *strcat(char *dest, char const *src);

/* strcmp() - compare two strings */
extern int strcmp(const char *s1, const char *s2);
extern int strncmp(const char *s1, const char *s2, size_t n);

/* strcpy(), strncpy() - copy a string. */
extern char *strncpy(char *dest, char const *str, size_t size);
extern char *strcpy(char *dest, char const *src);

/* strlen - calculate the lenght of a string. */
extern size_t strnlen(char const *str, size_t maxlen);
extern size_t strlen(char const *str);

/* strrchr() - find the last occurent of a byte */
extern char *strrchr(const char *s, int c);

/* strdup() - dump string */
extern char *strdup(const char *s);

#endif /*__STRING_H__*/
