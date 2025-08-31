#ifndef __STDIO_H
#define __STDIO_H

// Minimal stdio.h "support"
typedef unsigned size_t;
typedef int FILE;

FILE* fopen(const char* path, const char* mode);
int fclose(FILE* file);
size_t fread(void far* dst, size_t size, size_t nmemb, FILE* file);
size_t fwrite(const void far* src, size_t size, size_t nmemb, FILE* file);
int fseek(FILE *file, long offset, int origin);
long ftell(FILE *file);
int ferror(FILE* file);

#endif
