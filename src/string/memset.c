#include <string.h>

/*
** The  memset()  function fills the first n bytes of the memory area pointed to
** by s with the constant byte c.
**
** TODO: use DMA !
** TODO: use DSP ?
*/
void *memset(void *s, int c, size_t n)
{
	while ((int)--n >= 0)
		((uint8_t *) s)[n] = c;
	return (s);
}
