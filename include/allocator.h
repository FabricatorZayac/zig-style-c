#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <stddef.h>

enum AllocatorError {OutOfMemory};

typedef struct {
    void *ptr;
    const struct allocator_vtable {
        void *(*alloc)(void *self, size_t len);
        void (*free)(void *self, void *buf);
    } *vtable;
} allocator_t;

const extern struct allocator_mt {
    void *(*allocBytes)(allocator_t, size_t len);

    void *(*create)(allocator_t, size_t size);
    void *(*alloc)(allocator_t, size_t size, size_t n);
    void (*free)(allocator_t, void *data);
} allocator;

#endif // !ALLOCATOR_H_
