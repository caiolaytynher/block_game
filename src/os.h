#pragma once

#include "core.h"

typedef struct OS_Page_Size_Result {
    usize page_size;
    Error error;
} OS_Page_Size_Result;

extern OS_Page_Size_Result os_page_size();

// The memory size is always divisible by the page size.
typedef struct OS_Memory_Result {
    void* memory;
    usize size;
    Error error;
} OS_Memory_Result;

// Allocate the minimum amount of pages to hold the specified size.
extern OS_Memory_Result os_memory_commit(usize size);