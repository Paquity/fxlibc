#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *calloc(size_t nmemb, size_t size)
{
    if (size == 0 || nmemb == 0)
        return (NULL);

    void *ret = malloc(nmemb * size);
    if (ret == NULL)
        return (NULL);

    memset(ret, 0x00, size);
    return (ret);
}
