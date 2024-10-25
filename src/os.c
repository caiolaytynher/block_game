#include "os.h"

#if defined _WIN32
#include <Windows.h>
#endif

OS_Page_Size_Result os_get_page_size() {
    OS_Page_Size_Result result = {0};
#if defined _WIN32
    SYSTEM_INFO system_info = {0};
    GetSystemInfo(&system_info);
    result.page_size = system_info.dwPageSize;
    return result;
#else
    result.error = Error_Not_Implemented;
    return result;
#endif
}

OS_Memory_Result os_memory_commit(usize size) {
    OS_Memory_Result result = {0};
#if defined _WIN32
    usize page_size = os_get_page_size().page_size;
    usize page_count = 1 + size / page_size;
    usize allocation_size = page_size * page_count;
    void* memory = VirtualAlloc(NULL, allocation_size, MEM_COMMIT, PAGE_READWRITE);
    if (memory == NULL) {
        result.error = Error_Failed;
    }
    result.memory = memory;
    result.size = allocation_size;
    return result;
#else
    result.error = Error_Not_Implemented;
    return result;
#endif
}