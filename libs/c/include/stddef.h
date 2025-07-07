#ifndef _C_STDDEF_H
#define _C_STDDEF_H


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __INTELLISENSE__
typedef unsigned int size_t;
typedef int ptrdiff_t;
#else
typedef unsigned long size_t;
typedef long ptrdiff_t;
#endif

#define offsetof(type, member) ((size_t)&(((type*)0)->member))

#ifndef NULL
#define NULL 0
#endif

#ifndef __cplusplus
typedef unsigned short wchar_t;
#endif

#ifdef __cplusplus
};
#endif

#endif
