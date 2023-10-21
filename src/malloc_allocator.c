#include "malloc_allocator.h"
#include "allocator.h"
#include "slice.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void _free(void *ctx, void *slice) {
    (void)ctx;
    free(slice);
}

static char *_alloc(void *ctx, size_t size) {
    (void)ctx;
    return malloc(size);
}

const allocator_t malloc_allocator = {
    .ptr = NULL,
    .vtable = &(struct allocator_vtable) {
        .alloc = _alloc,
        .free = _free,
    },
};
