#include "memory.h"

Allocation_Result mem_alloc(usize size, Allocator allocator) {
    return allocator.proc(Allocation_Type_Alloc, NULL, 0, size);
}

Allocation_Result mem_realloc(void* memory, usize size, Allocator allocator) {
    return allocator.proc(Allocation_Type_Realloc, memory, 0, size);
}

Allocation_Result mem_resize( void* memory, usize old_size, usize new_size, Allocator allocator) {
    return allocator.proc(Allocation_Type_Resize, memory, old_size, new_size);
}

Error mem_dealloc(void* memory, Allocator allocator) {
    return allocator.proc(Allocation_Type_Dealloc, memory, 0, 0).error;
}

Error mem_reset(Allocator allocator) {
    return allocator.proc(Allocation_Type_Reset, NULL, 0, 0).error;
}