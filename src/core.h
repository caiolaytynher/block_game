#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h> // TODO(caio): make my own version

#define KiB(n) ((n) * 1024ull)
#define MiB(n) (KiB(n) * 1024ull)
#define GiB(n) (MiB(n) * 1024ull)

// TODO(caio): Replace print with log when the logging system is ready
#define panic(...)                                  \
    printf("Panic at %s:%d\n", __FILE__, __LINE__); \
    printf(""##__VA_ARGS__);                        \
    exit(1)
#define runtime_assert(expression, ...)                            \
    if (!(expression)) {                                           \
        printf("Assertion failed at %s:%d\n", __FILE__, __LINE__); \
        printf(#expression "\n");                                  \
        printf(""##__VA_ARGS__);                                   \
        exit(1);                                                   \
    }

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8, byte;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef ptrdiff_t isize;
typedef intptr_t intptr;

typedef size_t usize;
typedef uintptr_t uintptr;

typedef float f32;
typedef double f64;

typedef enum Error {
    Error_None,
    Error_Failed,
    Error_Invalid,
    Error_Not_Implemented
} Error;