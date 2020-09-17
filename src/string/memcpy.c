#include <string.h>

void *memcpy(void *dest, const void *src, size_t count)
{
	for (size_t i = 0 ; i < count ; i = i + 1)
		((uint8_t*)dest)[i] = ((uint8_t*)src)[i];
	return (dest);
}
