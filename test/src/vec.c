#include "vec.h"
#include "malloc_allocator.h"
#include <stdio.h>
#include <assert.h>

void vec_test(void) {
    Vec(int) foo = Vec.init(sizeof(int), malloc_allocator);

    APPEND(foo, 5);
    assert(len(foo) == 1);
    assert((*foo)[0] == 5);

    APPEND(foo, 2);
    assert(len(foo) == 2);
    assert((*foo)[1] == 2);

    Vec.deinit(foo);
}

int main(void) {
    vec_test();
}
