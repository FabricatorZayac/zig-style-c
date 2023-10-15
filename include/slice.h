#ifndef SLICE_H_
#define SLICE_H_

#include <stddef.h>

#include "cursed_macros.h"

typedef struct {
    void *data;
    size_t len;
} slice_t;

#define ARRAY(T, ...)             \
(void *)&(slice_t) {              \
    .data = &(T[]){__VA_ARGS__},  \
    .len = NUM_ARGS(__VA_ARGS__), \
}

static inline size_t len(void *slice) {
    return ((slice_t *)slice)->len;
}

#endif // !SLICE_H_
