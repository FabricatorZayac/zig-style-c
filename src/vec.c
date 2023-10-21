#include "vec.h"
#include "allocator.h"
#include "slice.h"
#include <stdint.h>
#include <string.h>

static void *init(size_t typesize, allocator_t allocator) {
    Vec_t *self = Allocator.create(allocator, sizeof(Vec_t));
    self->items = (slice_t){ .ptr = NULL, .len = 0, .elem_size = typesize };
    self->capacity = 0;
    self->allocator = allocator;
    return self;
}

static void deinit(void *_self) {
    Vec_t *self = _self;
    Allocator.free(self->allocator, self->items.ptr);
    Allocator.destroy(self->allocator, self);
}

static void ensureTotalCapacity(void *_self, size_t new_capacity) {
    Vec_t *self = _self;

    if (self->capacity >= new_capacity) return;

    size_t better_capacity = self->capacity;
    while (1) {
        better_capacity += better_capacity / 2 + 8;
        if (better_capacity >= new_capacity) break;
    }

    slice_t *new_memory = Allocator.alloc(
        self->allocator,
        self->items.elem_size,
        better_capacity
    );

    new_memory->elem_size = self->items.elem_size;
    new_memory->len = new_memory->len / self->items.elem_size;
    slicecpy(SLICE((char **)new_memory, 0, self->items.len), &self->items);

    Allocator.free(self->allocator, self->items.ptr);
    self->items.ptr = new_memory;
    self->capacity = len(new_memory);
}

const struct Vec_mt Vec = {
    .init = init,
    .deinit = deinit,
    .ensureTotalCapacity = ensureTotalCapacity,
};
