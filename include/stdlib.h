#ifndef __LIB_STDLIB_H__
# define __LIB_STDLIB_H__

#include <stddef.h>
#include <stdint.h>


#define HEAP_BLOCK_MIN		(16)
struct heap_block
{
	uint16_t status;		/* status of the block (1=used,0=free) */
	uint16_t size;			/* size of the block (without block header) */
} __attribute__((packed, aligned(2)));

struct heap_page
{
	void *brk;			/* break (address of the limit area) */
	size_t size;			/* Page size (without header) */
	struct heap_page *next;		/* Next heap page */
	struct heap_block heap;		/* Start of block informations */
} __attribute__((packed, aligned(4)));

// Functions
extern void *malloc(size_t size);
extern void *calloc(size_t nmemb, size_t size);
extern void *realloc(void *ptr, size_t size);
extern void *reallocarray(void *ptr, size_t nmemb, size_t size);
extern void free(void *ptr);

#endif /*__LIB_STDLIB_H__*/
