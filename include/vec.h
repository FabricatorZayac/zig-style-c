#ifndef VEC_H_
#define VEC_H_

#include "allocator.h"
#include "class.h"
#include <stddef.h>

typedef struct Vec {
    void *data;
    Class_t T;
    size_t capacity;
    allocator_t allocator;
} Vec_t;

extern struct VecClass {
    Vec_t (*init)(Class_t T, allocator_t allocator);
    void (*deinit)(Vec_t *self);
    size_t (*len)(Vec_t *self);
    void *(*at)(Vec_t *self, size_t idx);
} Vec;

#endif // !VEC_H_
