#ifndef __LIB_STDLIB_H__
# define __LIB_STDLIB_H__

#include <stddef.h>
#include <stdint.h>

//---
// Dynamic memory management
//---
/* Allocate SIZE bytes of memory. */
extern void *malloc(size_t size);

/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0. */
extern void *calloc(size_t nmemb, size_t size);

/*
** Re-allocate the previously allocated block in PTR, making the new block
** SIZE bytes long.
*/
extern void *realloc(void *ptr, size_t size);

/*
** Re-allocate the previously allocated block in PTR, making the new block large
** enough for NMEMB elements of SIZE bytes each.
*/
extern void *reallocarray(void *ptr, size_t nmemb, size_t size);

/* Free a block allocated by `malloc', `realloc' or `calloc'. */
extern void free(void *ptr);

#endif /*__LIB_STDLIB_H__*/
