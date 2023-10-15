#include "allocator.h"
#include "slice.h"
#include <stddef.h>
#include <assert.h>

static void *rawAlloc(allocator_t self, size_t len) {
    return self.vtable->alloc(self.ptr, len);
}
static void rawFree(allocator_t self, void *buf) {
    self.vtable->free(self.ptr, buf);
}

static void *aalloc(allocator_t self, size_t size, size_t n) {
    slice_t *data = rawAlloc(self, size * n);
    data->len /= size;
    assert(data->len == n);
    return data;
}

const struct allocator_mt allocator = {
    .allocBytes = rawAlloc,

    .alloc = aalloc,
    .free = rawFree,
};
