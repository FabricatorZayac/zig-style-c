#include "allocator.h"

Bytes_t Allocator_rawAlloc(Allocator_t self, size_t len) {
    return self.vtable->alloc(self.ptr, len);
}
void Allocator_rawFree(Allocator_t self, Bytes_t buf) {
    self.vtable->free(self.ptr, buf);
}

const struct AllocatorClass Allocator = {
    .rawAlloc = Allocator_rawAlloc,
    .rawFree = Allocator_rawFree,
};
