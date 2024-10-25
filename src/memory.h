#pragma once

#include "core.h"

#define ALLOCATOR_DEFAULT_ALIGNMENT (2 * sizeof(void*))

typedef struct Arena {
    byte* buffer;
    usize length;
    usize current_offset;
    usize previous_offset;
    usize alignment;
    struct Arena* next;
} Arena;

// The size of the arena is added back in the creation procedure
#define ARENA_DEFAULT_SIZE (KiB(4) - sizeof(Arena))

typedef enum Allocator_Mode {
    Allocator_Mode_Alloc,
    Allocator_Mode_Dealloc,
    Allocator_Mode_Resize,
    Allocator_Mode_Reset
} Allocator_Mode;

typedef struct Allocator_Result {
    void* memory;
    Error error;
} Allocator_Result;

typedef union Allocator_Data {
    Arena* arena;
} Allocator_Data;

typedef Allocator_Result (*Allocator_Proc)(Allocator_Data data,
                                           Allocator_Mode mode,
                                           void* memory,
                                           usize old_size,
                                           usize new_size);

typedef struct Allocator {
    Allocator_Data data;
    Allocator_Proc proc;
} Allocator;

extern Allocator_Result allocator_alloc(Allocator allocator, usize size);
extern Allocator_Result allocator_resize(Allocator allocator, void *memory, usize old_size, usize new_size);
extern Error allocator_dealloc(Allocator allocator, void *memory);
extern Error allocator_reset(Allocator allocator);

extern Allocator arena_allocator_create(usize size, usize alingment);
extern Allocator arena_allocator_create_default();