#ifndef __LIB_PTHREAD_H__
# define __LIB_PTHREAD_H__

#include <stddef.h>
#include <stdint.h>

//---
// Warnig, this part is experimental and reserved for Vhex
//---

// Define Mutex type
enum {
	mtx_plain     = 0,
	mtx_recursive = 1,
	mtx_timed     = 2
};

// Define mutex structure
// @note: This is a custom implementation
#define MTX_WATERMARK	(0xdeadbeef)
struct __mtx_s
{
	uint32_t __watermark;
	uint16_t lock;
	uint8_t type;
} __attribute__((packed, aligned(4)));
typedef struct __mtx_s mtx_t;


//---
// Mutex functions
//---

/*
** Creates a new mutex object with type __TYPE.
** @note: If successful the new object is pointed by __MUTEX.
*/
extern int mtx_init(mtx_t *__mutex, int __type);

/*
** Block the current thread until the mutex pointed to by __MUTEX is unlocked.
** In that case current thread will not be blocked.
*/
extern int mtx_lock(mtx_t *__mutex);

/*
** Try to lock the mutex pointed by __MUTEX without blocking.
** @note: If the mutex is free the current threads takes control of it,
** otherwise it returns immediately.
*/
extern int mtx_trylock(mtx_t *__mutex);

/*
** Unlock the mutex pointed by __MUTEX.
** @note: It may potentially awake other threads waiting on this mutex.
*/
extern int mtx_unlock (mtx_t *__mutex);

/* Destroy the mutex object pointed by __MUTEX. */
extern void mtx_destroy(mtx_t *__mutex);


//---
// Atomic operations
//---
/*
** Save the current SR register and set the SR.BIT bit up (start atomic operations)
** @note: return the saved SR register (if has been saved), 0xffffffff otherwise.
*/
extern uint32_t __thread_atomic_start(void);

/*
** Restore the saved SR register
** @note: return the restored SR register or -1 otherwise.
*/
extern uint32_t __thread_atomic_stop(void);

#endif /*__LIB_PTHREAD_H__*/
