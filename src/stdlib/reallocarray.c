#include <stdlib.h>

//FIXME: check safe !!!!
//FIXME: Check underflow !!
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}
