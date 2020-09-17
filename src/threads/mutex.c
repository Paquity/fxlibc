#include <threads.h>
#include <unistd.h>

// Creates a new mutex object with type __TYPE.
// @note: If successful the new object is pointed by __MUTEX.
int mtx_init (mtx_t *__mutex, int __type)
{
	// Check if the mutext is already initialized
	if (__mutex->__watermark == MTX_WATERMARK)
		return (-1);

	// Initialize mutex
	__mutex->__watermark = MTX_WATERMARK;
	__mutex->type = __type;
	__mutex->lock = 0;
	return (0);
}

// Block the current thread until the mutex pointed to by __MUTEX is unlocked. 
// In that case current thread will not be blocked.
int mtx_lock(mtx_t *__mutex)
{
	// Check mutex validity
	if (__mutex->__watermark != MTX_WATERMARK)
		return (-1);

	// Wait util the mutex is unlocked
	while (1)
	{
		// Check if the mutex is unlock
		__thread_atomic_start();
		if (__mutex->lock == 0)
			break;
		__thread_atomic_stop();

		// TODO: force kernel schedule
		__asm__ volatile ("sleep");
	}

	//TODO: handle mutex type !!
	(void)__mutex->type;

	// Lock the mutex
	__mutex->lock = 1;

	// Stop atomic operations
	__thread_atomic_stop();
	return (0);
}

// Try to lock the mutex pointed by __MUTEX without blocking.
// @note: If the mutex is free the current threads takes control of it,
// otherwise it returns immediately.
int mtx_trylock(mtx_t *__mutex)
{
	// Check mutex validity
	if (__mutex->__watermark != MTX_WATERMARK)
		return (-1);
	
	// Start atomic operations
	__thread_atomic_start();

	// Check if the mutex is already free
	int ret = -1;
	if (__mutex->lock == 0)
	{
		//TODO: handle mutex type !!
		(void)__mutex->type;

		// lock the mutex and change the return value
		__mutex->lock = 1;
		ret = 0;
	}

	// Stop atomic operation and return
	__thread_atomic_stop();
	return (ret);
}

// Unlock the mutex pointed by __MUTEX.
// @note: It may potentially awake other threads waiting on this mutex.
int mtx_unlock(mtx_t *__mutex)
{
	// Check mutex validity
	if (__mutex->__watermark != MTX_WATERMARK)
		return (-1);

	// Start atomic operation
	__thread_atomic_start();

	// Check if the mutex is realy used and unluck if needed
	int ret = -1;
	if (__mutex->lock != 0) {
		__mutex->lock = 0;
		ret = 0;
	}

	// Stop atomic operation and return
	__thread_atomic_stop();
	return (ret);
}

// Destroy the mutex object pointed by __MUTEX.
// TODO: check if the mutex is in use ?
void mtx_destroy(mtx_t *__mutex)
{
	__mutex->__watermark = 0x00000000;
	__mutex->type = -1;
}
