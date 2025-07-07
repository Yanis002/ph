#ifndef _C_ASSERT_H
#define _C_ASSERT_H

void __assert_failed(char *condition, char *fileName, char *functionName, int lineNumber);

// clang-format off
#define assert(cond) if (!(cond)) { __assert_failed(#cond, __FILE__, __FUNCTION__, __LINE__); }
// clang-format on

#endif
