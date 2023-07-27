#include "allocator.h"
#include "malloc_allocator.h"
#include <stdio.h>
#include <assert.h>

typedef struct {
    int *ptr;
    size_t len;
} IntSlice_t;

void raw() {
    IntSlice_t int_buf = BYTES_AS_SLICE(
            int, Allocator.rawAlloc(malloc_allocator, sizeof(int[5])));

    assert(int_buf.len == 5);

    for (size_t i = 0; i < int_buf.len; i++) {
        int_buf.ptr[i] = i * 2;
    }

    for (size_t i = 0; i < int_buf.len; i++) {
        assert(int_buf.ptr[i] == (int)i * 2);
    }

    Allocator.rawFree(malloc_allocator, SLICE_AS_BYTES(int_buf));
}

int main() {
    raw();
}
