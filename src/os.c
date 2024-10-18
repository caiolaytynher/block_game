#include "os.h"

#if defined _WIN32
#include <Windows.h>
#endif

Page_Size_Result os_page_size() {
    Page_Size_Result result = {0};
#if defined _WIN32
    LPSYSTEM_INFO system_info;
    GetSystemInfo(system_info);
    result.page_size = system_info->dwPageSize;
    return result;
#else
    result.error = Error_Not_Implemented;
    return result;
#endif
}

Page_Result os_commit_memory(usize size) {
    Page_Result result = {0};
#if defined _WIN32
    result.page.count = 1 + size / os_page_size().page_size;
    result.page.memory = VirtualAlloc(NULL, result.page.count, MEM_COMMIT, PAGE_READWRITE);
    if (result.memory == NULL) {
        result.error = Error_Failed;
    }
    return result;
#else
    result.error = Error_Not_Implemented;
    return result;
#endif
}