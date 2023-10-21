#ifndef SLICE_H_
#define SLICE_H_

#include <stddef.h>
#include <string.h>

#include "cursed_macros.h"

typedef struct {
    void *ptr;
    size_t len;
    size_t elem_size;
} slice_t;

// generic alias
#define slice(T) T **

#define ARRAY(T, ...)             \
(void *)&(slice_t) {              \
    .ptr = &(T[]){__VA_ARGS__},   \
    .len = NUM_ARGS(__VA_ARGS__), \
    .elem_size = sizeof(T),       \
}

static inline size_t len(void *slice) {
    return ((slice_t *)slice)->len;
}

#define SLICE(SL, BEGIN, END)                \
(void *)&(slice_t) {                         \
    .ptr = &(*SL)[BEGIN],                    \
    .len = END - BEGIN,                      \
    .elem_size = ((slice_t *)SL)->elem_size, \
}

static inline void slicecpy(void *restrict _dest, const void *restrict _src) {
    slice_t *restrict dest = _dest;
    const slice_t *restrict src = _src;

    if (dest->len == src->len && dest->elem_size == src->elem_size) {
        memcpy(dest->ptr, src->ptr, len((void *)src));
    }
}

#endif // !SLICE_H_
