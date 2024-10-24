#pragma once

#include "core.h"

#define DEFAULT_ALIGNMENT (2 * sizeof(void*))

// NOTE(caio): I'm guessing that this could be used throughout all allocators.
// If I'm wrong, it's easy to change later.
typedef struct Memory_Buffer_List {
    byte* buffer;
    usize length;
    Memory_Buffer_List* next;
} Memory_Buffer_List;

typedef struct Arena {
    Memory_Buffer_List buffer_list;
    usize current_offset;
    usize previous_offset;
    usize alignment;
} Arena;

typedef enum Allocator_Mode {
    Allocator_Mode_Alloc,
    Allocator_Mode_Dealloc,
    Allocator_Mode_Realloc,
    Allocator_Mode_Resize,
    Allocator_Mode_Reset
} Allocator_Mode;

typedef struct Allocator_Result {
    void *memory;
    Error error;
} Allocator_Result;

typedef Allocator_Result (*Allocator_Proc)(Allocator_Mode type, void *memory, usize old_size, usize new_size);

typedef union Allocator_Data {
    Arena *arena;
} Allocator_Data;

typedef struct Allocator {
    Allocator_Data data;
    Allocator_Proc proc;
} Allocator;

extern Allocator_Result allocator_alloc(Allocator allocator, usize size);
extern Allocator_Result allocator_realloc(Allocator allocator, void *memory, usize size);
extern Allocator_Result allocator_resize(Allocator allocator, void *memory, usize old_size, usize new_size);
extern Error allocator_dealloc(Allocator allocator, void *memory);
extern Error allocator_reset(Allocator allocator);

extern Allocator arena_allocator_make();