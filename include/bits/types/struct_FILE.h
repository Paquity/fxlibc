#ifndef __FILE_H__
# define __FILE_H__

#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

//TODO: remove me !!!
#include <kernel/bits/filesystem.h>

// Define _IO_FILE 
// TODO: add open flags
// TODO: add file descriptor ?
// TODO: update me !
struct _IO_FILE
{
    off_t cursor;
    int permission;
    struct file_operations *file_op;
    void *private;
};

#endif /*__FILE_H__*/
