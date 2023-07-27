#ifndef MALLOC_ALLOCATOR_H_
#define MALLOC_ALLOCATOR_H_

#include "allocator.h"

const extern struct MallocAllocator {
    struct AllocatorVTable vtable;
} MallocAllocator;

const extern Allocator_t malloc_allocator;

#endif // !MALLOC_ALLOCATOR_H_
