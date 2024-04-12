#ifndef PH_GLOBAL_H
#define PH_GLOBAL_H

#define NULL 0

#define GET_FLAG(arr, pos) (((1 << ((pos)&0x1f)) & (arr)[((u32)(pos)) >> 5]) != 0)
#define SET_FLAG(arr, pos) ((arr)[((u32)(pos)) >> 5] |= 1 << ((pos)&0x1f))
#define RESET_FLAG(arr, pos) ((arr)[((u32)(pos)) >> 5] &= ~(1 << ((pos)&0x1f)))

// NONMATCH(name) marks the function `name` as nonmatching
// The reason for the macro is to easily detect it in progress.py
#ifdef NONMATCHING
#define NONMATCH(name) name
#else
#define NONMATCH(name) asm name
#endif

// Prevent the IDE from reporting errors that the compiler/linker won't report
#ifdef __INTELLISENSE__
#endif

#define ARM _Pragma("thumb off")
#define THUMB _Pragma("thumb on")

// `override` was added in C++11 before the DS, so we only use the keyword to indicate overriden functions
#define override

// Define .sbss variables by using #pragma section sbss begin|end
#pragma define_section sbss ".data" \
                            ".sbss"

#endif
