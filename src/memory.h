#pragma once

#include "core.h"

#define DEFAULT_ALIGNMENT (2 * sizeof(void*))

typedef enum Allocation_Type {
    Allocation_Type_Alloc,
    Allocation_Type_Dealloc,
    Allocation_Type_Realloc,
    Allocation_Type_Resize,
    Allocation_Type_Reset
} Allocation_Type;

typedef struct Allocation_Result {
    void* memory;
    Error error;
} Allocation_Result;

typedef Allocation_Result (*Allocator_Proc)(Allocation_Type type, void* memory, usize old_size, usize new_size);

typedef struct Allocator {
    void* data;
    Allocator_Proc proc;
} Allocator;

extern Allocation_Result mem_alloc(usize size, Allocator allocator);
extern Allocation_Result mem_realloc(void* memory, usize size, Allocator allocator);
extern Allocation_Result mem_resize(void* memory, usize old_size, usize new_size, Allocator allocator);
extern void mem_dealloc(void* memory, Allocator allocator);
extern void mem_reset(Allocator allocator);