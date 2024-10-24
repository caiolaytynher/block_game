#include "memory.h"

Allocator_Result allocator_alloc(Allocator allocator, usize size) {
    return allocator.proc(Allocator_Mode_Alloc, NULL, 0, size);
}

Allocator_Result allocator_realloc(Allocator allocator, void* memory, usize size) {
    return allocator.proc(Allocator_Mode_Realloc, memory, 0, size);
}

Allocator_Result allocator_resize(Allocator allocator, void* memory, usize old_size, usize new_size) {
    return allocator.proc(Allocator_Mode_Resize, memory, old_size, new_size);
}

Error allocator_dealloc(Allocator allocator, void* memory) {
    return allocator.proc(Allocator_Mode_Dealloc, memory, 0, 0).error;
}

Error allocator_reset(Allocator allocator) {
    return allocator.proc(Allocator_Mode_Reset, NULL, 0, 0).error;
}