#ifndef __FILE_H__
# define __FILE_H__

#include <stdint.h>
#include <stddef.h>

#include <fxlibc/sys/types.h>

//---
// TODO: VFS abstraction ? or ABI-spesific abstraction ?
//---


// Define _IO_FILE
// TODO: add open flags
// TODO: add file descriptor ?
// TODO: update me !
struct _IO_FILE
{
    off_t cursor;
    int permission;
    void *file_op;
    void *private;
};

#endif /*__FILE_H__*/
