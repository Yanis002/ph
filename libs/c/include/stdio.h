#ifndef _C_STDIO_H
#define _C_STDIO_H

#define FILENAME_MAX 256

typedef struct FILE {
    // TODO
} FILE;

int printf(const char* format, ...);
int fprintf(FILE* stream, const char* format, ...);
int sprintf(char *__restrict s, const char *__restrict format, ...);
int snprintf(char* s, size_t n, const char* format, ...);

int scanf(const char* format, ...);
int fscanf(FILE* stream, const char* format, ...);
int sscanf(const char* buffer, const char* format, ...);

#endif
