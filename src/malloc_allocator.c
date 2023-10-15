#include "malloc_allocator.h"
#include "allocator.h"
#include "slice.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void mfree(void *ctx, void *slice) {
    (void)ctx;
    free(slice);
}

static void *mallocate(void *ctx, size_t size) {
    (void)ctx;
    slice_t *buf = malloc(size + sizeof(slice_t));
    buf->data = buf + 1;
    buf->len = size;
    memset(buf->data, 0, size);
    return buf;
}

const struct mallocator MallocAllocator = {
    .vtable = {
        .alloc = mallocate,
        .free = mfree,
    }
};

const allocator_t malloc_allocator = {
    .ptr = NULL,
    .vtable = &MallocAllocator.vtable,
};
