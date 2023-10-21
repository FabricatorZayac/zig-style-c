#include "allocator.h"
#include "slice.h"
#include <stddef.h>
#include <assert.h>

static char *rawAlloc(allocator_t self, size_t len) {
    return self.vtable->alloc(self.ptr, len);
}
static void rawFree(allocator_t self, void *buf) {
    self.vtable->free(self.ptr, buf);
}

static void *_alloc(allocator_t self, size_t typesize, size_t n) {
    slice_t *data = (slice_t *)rawAlloc(self, typesize * n + sizeof(slice_t));
    data->ptr = data + 1;
    data->len = n;
    data->elem_size = typesize;
    return data;
}

static void *create(allocator_t self, size_t typesize) {
    return rawAlloc(self, typesize);
}

static void destroy(allocator_t self, void *ptr) {
    rawFree(self, ptr);
}

const struct allocator_mt Allocator = {
    .rawAlloc = rawAlloc,

    .create = create,
    .destroy = destroy,
    .alloc = _alloc,
    .free = rawFree,
};
