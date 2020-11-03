#include <fxlibc/string.h>

/*
** The memcpy() function copies n bytes from memory area src to memory area dest.
** The memory areas must not overlap.  Use memmove(3) if the memory areas do
** overlap.
**
** TODO: use DMA ?
** TODO: use DSP ?
*/
void *memcpy(void *dest, const void *src, size_t count)
{
	for (size_t i = 0; i < count; i = i + 1)
		((uint8_t *) dest)[i] = ((uint8_t *) src)[i];
	return (dest);
}
