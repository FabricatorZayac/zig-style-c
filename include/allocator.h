#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <stddef.h>

typedef struct {
    void *ptr;
    const struct allocator_vtable {
        char *(*alloc)(void *self, size_t len);
        void (*free)(void *self, void *slice);
    } *vtable;
} allocator_t;

const extern struct allocator_mt {
    char *(*rawAlloc)(allocator_t, size_t len);
    void (*rawFree)(allocator_t, void *slice);

    void *(*create)(allocator_t, size_t size);
    void *(*alloc)(allocator_t, size_t size, size_t n);
    void (*destroy)(allocator_t, void *ptr);
    void (*free)(allocator_t, void *memory);
} Allocator;

#endif // !ALLOCATOR_H_
