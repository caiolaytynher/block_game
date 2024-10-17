#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define KiB(n) ((n) * 1024ull)
#define MiB(n) (KiB(n) * 1024ull)
#define GiB(n) (MiB(n) * 1024ull)

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8, byte;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef ptrdiff_t isize;
typedef size_t usize;
typedef intptr_t intptr;
typedef uintptr_t uintptr;

typedef float f32;
typedef double f64;