#include <fxlibc/stdlib.h>
#include <fxlibc/string.h>
#include <fxlibc/unistd.h>

/*
** The calloc() function allocates memory for an array of nmemb elements of size
** bytes each and returns a pointer to the allocated memory. The memory is set
** to zero. If nmemb or size is 0, then calloc() returns either NULL, or a
** unique pointer value that can later be successfully passed to free(). If the
** multiplication of nmemb and size would  result  in  integer  overflow, then
** calloc() returns an error. By contrast, an integer overflow would not be
** detected in the following call to malloc(), with the result that an incorrectly
** sized block of memory  would  be allocated: `malloc(nmemb * size);`
*/
void *calloc(size_t nmemb, size_t size)
{
	// check error
	if (size == 0 || nmemb == 0)
		return (NULL);

	// Try to allowate the area
	void *ret = malloc(nmemb * size);
	if (ret == NULL)
		return (NULL);

	// wipe the area
	memset(ret, 0x00, size);
	return (ret);
}
