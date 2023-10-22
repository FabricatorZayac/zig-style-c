#include "allocator.h"
#include "heap.h"
#include "slice.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void alloc_test(void) {
    allocator_t a = malloc_allocator;
    slice(int) foo = Allocator.alloc(a, sizeof(int), 5);

    assert(len(foo) == 5);

    for (size_t i = 0; i < len(foo); i++) {
        (*foo)[i] = i * 2;
    }

    for (size_t i = 0; i < len(foo); i++) {
        assert((*foo)[i] == (int)i * 2);
    }

    Allocator.free(a, foo);
}

void create_test(void) {
    allocator_t a = malloc_allocator;
    int *foo = Allocator.create(a, sizeof(int));

    *foo = 5;
    assert(*foo == 5);

    Allocator.destroy(a, foo);
}

int main(void) {
    alloc_test();
    // create_test();

    slice(int) arr = ARRAY(int, 6, 2, 1);
    assert(len(arr) == 3);

    slice(int) sl = SLICE(arr, 0, 2);
    assert(len(sl) == 2);
}
