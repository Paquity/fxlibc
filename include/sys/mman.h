#ifndef __LIB_SYS_MMAN_H__
# define __LIB_SYS_MMAN_H__

#include <stddef.h>
#include <stdint.h>

#ifndef __KERNEL_MEMORY_H__
// mapping flags
// Protection (unused)
#define PROT_READ	0x1		/* Page can be read.  */
#define PROT_WRITE	0x2		/* Page can be written.  */
#define PROT_EXEC	0x4		/* Page can be executed.  */
#define PROT_NONE	0x0		/* Page can not be accessed.  */

// Mapping flags
#define MAP_SHARED	0x01		/* Share changes.  */
#define MAP_PRIVATE	0x02		/* Changes are private.  */
#define MAP_ANONYMOUS	0x20		/* Don't use a file.  */
#define MAP_ANON	MAP_ANONYMOUS	/* Don't use a file.  */
#define MAP_FILE	0		/* Ignored.  */
#define MAP_GROWSDOWN	0x00100		/* Stack-like segment.  */
#define MAP_DENYWRITE	0x00800		/* ETXTBSY.  */
#define MAP_EXECUTABLE	0x01000		/* Mark it as an executable.  */
#define MAP_LOCKED	0x02000		/* Lock the mapping.  */
#define MAP_NORESERVE	0x04000		/* Don't check for reservations.  */
#define MAP_POPULATE	0x08000		/* Populate (prefault) pagetables.  */
#define MAP_NONBLOCK	0x10000		/* Do not block on IO.  */
#define MAP_STACK	0x20000		/* Allocation is for a stack.  */
#define MAP_HUGETLB	0x40000		/* Create huge page mapping.  */
#define MAP_SYNC	0x80000		/* Perform synchronous page
					   faults for the mapping.  */
#define MAP_FIXED_NOREPLACE 0x100000	/* MAP_FIXED but do not unmap
					   underlying mapping.  */
#define MAP_UNINITIALIZED   0x200000	/* Don't clear anonymous page */

// Value returned when mmap value
#define MAP_FAILED	((void*) -1)
#endif

// Prototype
extern void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
extern int munmap(void *addr, size_t length);

#endif /*__LIB_SYS_MMAN_H__*/
