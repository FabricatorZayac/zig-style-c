#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <stddef.h>

// result of sizeof, cheap generic
typedef size_t typesize;

typedef struct {
    char *ptr;
    size_t len;
} Bytes_t;

#define BYTES_AS_SLICE(T, BYTES) \
{ .ptr = (T *)BYTES.ptr, .len = BYTES.len / sizeof(T) }
#define SLICE_AS_BYTES(SLICE) \
(Bytes_t){ .ptr = (char *)SLICE.ptr, .len = SLICE.len * sizeof(*SLICE.ptr) }

enum AllocatorError {OutOfMemory = -1};

typedef struct Allocator {
    void *ptr;
    const struct AllocatorVTable {
        Bytes_t (*alloc)(void *self, size_t len);
        void (*free)(void *self, Bytes_t buf);
    } *vtable;
} Allocator_t;

// I don't really want to call them classes, because it's a dirty word
// and it's not really what this is, it's more of a method table
const extern struct AllocatorClass {
    Bytes_t (*rawAlloc)(Allocator_t self, size_t len);
    void (*rawFree)(Allocator_t self, Bytes_t buf);
} Allocator;

#endif // !ALLOCATOR_H_
