#pragma once

#include "core.h"

typedef struct Page_Size_Result {
    usize page_size;
    Error error;
} Page_Size_Result;

extern Page_Size_Result os_page_size();

typedef struct Page {
    void* memory;
    usize count;
} Page;

typedef struct Page_Result {
    Page page;
    Error error;
}

extern Page_Result os_commit_memory(usize size);