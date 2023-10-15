#ifndef MALLOC_ALLOCATOR_H_
#define MALLOC_ALLOCATOR_H_

#include "allocator.h"

const extern struct mallocator {
    struct allocator_vtable vtable;
} MallocAllocator;

const extern allocator_t malloc_allocator;

#endif // !MALLOC_ALLOCATOR_H_
