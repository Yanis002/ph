#pragma once

#include "global.h"
#include "types.h"

// Q20.12 fixed point number
typedef s32 q20;
// Q4.12 fixed point number
typedef s16 q4;

#define INT_TO_Q20(n) ((s32)((n) << 12))
#define FLOAT_TO_Q20(n) ((s32)(((n)*8192 + 1) / 2))

#define ROUND_Q20(n) (((s32)(n) + 0x800) >> 12)

typedef struct {
    /* 0 */ q20 x;
    /* 4 */ q20 y;
    /* 8 */ q20 z;
    /* c */
} Vec3p;

typedef struct {
    /* 00 */ q20 x;
    /* 04 */ q20 y;
    /* 08 */ q20 z;
    /* 0c */ q20 w;
    /* 10 */
} Vec4p;

typedef struct {
    /* 00 */ Vec3p xColumn;
    /* 0c */ Vec3p yColumn;
    /* 18 */ Vec3p zColumn;
    /* 24 */
} Mat3p;

extern "C" u32 FastDivide(u32 a, u32 b);
extern "C" u32 Divide(u32 a, u32 b);
extern "C" bool Approach(unk32* src, unk32 dest, unk32 step);
extern "C" bool Approach_thunk(unk32* src, unk32 dest, unk32 step);
extern "C" bool func_01ffec34(Vec4p* param1, Vec4p* param2);
