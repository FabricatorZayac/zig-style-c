#include "vec.h"
#include "allocator.h"
#include "class.h"
#include <stdint.h>
#include <string.h>

typedef Vec_t Self;
typedef struct VecClass Class;

// Vec_t Vec_init(Class_t T, Allocator_t allocator) {
//     return (Self){
//         .T = T,
//         .allocator = allocator,
//         .data = { .ptr = NULL, .len = 0 }
//     };
// }
//
// void Vec_deinit(Self *self) {
//     Allocator.rawFree(self->allocator, self->data);
// }
//
// size_t Vec_len(Self *self) { return self->data.len * self->T.size; }
//
// void Vec_ensureTotalCapacity(Self *self, size_t new_capacity) {
//     if (self->T.size == 0) {
//         self->capacity = SIZE_MAX;
//         return;
//     }
//     if (self->capacity >= new_capacity) return;
//
//     Bytes_t old_memory = self->data;
//     Bytes_t new_memory = Allocator.rawAlloc(self->allocator, new_capacity * self->T.size);
//     memcpy(new_memory.ptr, old_memory.ptr, old_memory.len);
//     Allocator.rawFree(self->allocator, old_memory);
//     self->data.ptr = new_memory.ptr;
// }
//
// void *Vec_at(Self *self, size_t idx) {
//     if (self->data.len / self->T.size < idx) {
//         return NULL;
//     }
//     return &self->data.ptr[idx * self->T.size];
// }
//
// Class Vec = {
//     .init = Vec_init,
//     .deinit = Vec_deinit,
//     .len = Vec_len,
//     .at = Vec_at,
// };
