#ifndef PH_TYPES_H
#define PH_TYPES_H

#include <stddef.h>

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float f32;
typedef double f64;
typedef volatile f32 vf32;
typedef volatile f64 vf64;

typedef int BOOL;

typedef s8 unk8;
typedef s16 unk16;
typedef s32 unk32;

#ifndef __cplusplus
typedef s32 bool;
#endif

#define CEIL_DIV(a, b) (((a) + (b) - 1) / (b))
#define UNK_PTR unk32 *

#endif
