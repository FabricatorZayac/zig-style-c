#include "malloc_allocator.h"
#include "allocator.h"
#include <stdlib.h>

void m_free(void *self, Bytes_t slice) {
    (void)self;
    free(slice.ptr);
}

Bytes_t m_alloc(void *self, size_t len) {
    (void)self;
    void *buf = malloc(len);
    // TODO: add error checking and maybe a result type
    return (Bytes_t){
        .ptr = buf,
        .len = len,
    };
}

const struct MallocAllocator MallocAllocator = {
    .vtable = {
        .alloc = m_alloc,
        .free = m_free,
    }
};

const Allocator_t malloc_allocator = {
    .ptr = NULL,
    .vtable = &MallocAllocator.vtable,
};
