#include "memory.h"
#include "os.h"

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

Allocation_Result arena_allocator_proc(Allocation_Type type, void* memory, usize old_size, usize new_size) {

}

Allocator arena_allocator_make() {
    Page_Size_Result page_size_result = os_page_size();
    assert(!page_size_result.error);
    usize page_size = page_size_result.page_size;

    Page_Result page_result = os_commit_memory(page_size);
    assert(!page_result.error);
    Page page = page_result.page;

    Arena* arena = page_result.page.memory;
    arena->buffer = (byte*)(arena + 1);
    arena->length = page_result.page.count * page_size - sizeof(Arena);
    arena->previous_offset = 0;
    arena->current_offset = 0;
    arena->alignment = DEFAULT_ALIGNMENT;
    arena->next = NULL;

    Allocator allocator = {0};
    allocator.data = arena;
    allocator.proc = arena_allocator_proc;
}