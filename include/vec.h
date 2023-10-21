#ifndef VEC_H_
#define VEC_H_

#include "allocator.h"
#include "slice.h"
#include <stddef.h>

typedef struct {
    slice_t items;
    size_t capacity;
    allocator_t allocator;
} Vec_t;

extern const struct Vec_mt {
    void *(*init)(size_t typesize, allocator_t allocator);
    void (*deinit)(void *self);
    void (*ensureTotalCapacity)(void *self, size_t new_capacity);
} Vec;

#define APPEND(VEC, ITEM)                       \
    Vec.ensureTotalCapacity(VEC, len(VEC) + 1); \
    (*VEC)[len(VEC)] = ITEM;                    \
    ((slice_t *)VEC)->len += 1

// generic alias
#define Vec(T) T **

#endif // !VEC_H_
