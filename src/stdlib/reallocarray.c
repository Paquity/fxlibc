#include <fxlibc/stdlib.h>

/*
** The reallocarray() function changes the size of the memory block pointed to
** by ptr to be large enough for an array of nmemb elements, each of which is
** size bytes. It is equivalent to the call: `realloc(ptr, nmemb * size);`
**
** However, unlike that realloc() call, reallocarray() fails safely in the case
** where the multiplication would overflow. If such an overflow occurs,
** reallocarray() returns NULL, sets errno to ENOMEM, and leaves the original
** block of memory unchanged.
**
** FIXME: check safe !!!!
** FIXME: Check underflow !!
*/
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return (realloc(ptr, nmemb * size));
}
