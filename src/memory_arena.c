#include "memory.h"
#include "os.h"

static Allocator_Result arena_allocator_proc(
    Allocator_Data data,
    Allocator_Mode mode,
    void* memory,
    usize old_size,
    usize new_size
) {
    Allocator_Result result = {0};
    Arena* arena = data.arena;
    switch (mode) {
    case Allocator_Mode_Alloc: {

    } break;
    default:
        result.error = Error_Invalid
    }
}

Allocator arena_allocator_create(usize size, usize alignment) {
    OS_Memory_Result memory_result = os_memory_commit(size + sizeof(Arena));
    runtime_assert(!memory_result.error);

    Arena* arena = memory_result.memory;
    arena->buffer = (byte*)(arena + 1);
    arena->length = memory_result.size - sizeof(Arena);
    arena->previous_offset = 0;
    arena->current_offset = 0;
    arena->alignment = alignment;
    arena->next = NULL;

    Allocator allocator = {0};
    allocator.data.arena = arena;
    allocator.proc = arena_allocator_proc;
    return allocator;
}

Allocator arena_allocator_create_default() {
    return arena_allocator_create(ARENA_DEFAULT_SIZE, ALLOCATOR_DEFAULT_ALIGNMENT);
}