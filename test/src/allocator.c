#include "allocator.h"
#include "fixed_buffer_allocator.h"
#include "malloc_allocator.h"
#include "slice.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void raw_test(void) {
    allocator_t a = malloc_allocator;
    int **foo = allocator.allocBytes(a, sizeof(int[5]));

    assert(len(foo) == sizeof(int[5]));

    for (size_t i = 0; i < len(foo) / sizeof(int); i++) {
        (*foo)[i] = i * 2;
    }

    for (size_t i = 0; i < len(foo) / sizeof(int); i++) {
        assert((*foo)[i] == (int)i * 2);
    }

    allocator.free(a, foo);
}

void alloc_test(void) {
    allocator_t a = malloc_allocator;
    int **foo = allocator.alloc(a, sizeof(int), 5);

    assert(len(foo) == 5);

    for (size_t i = 0; i < len(foo); i++) {
        (*foo)[i] = i * 2;
    }

    for (size_t i = 0; i < len(foo); i++) {
        assert((*foo)[i] == (int)i * 2);
    }

    allocator.free(a, foo);
}

int main(void) {
    raw_test();
    alloc_test();

    int **arr = ARRAY(int, 6, 2, 1);
    assert(len(arr) == 3);
}
