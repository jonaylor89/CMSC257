
#ifndef ASGN3_SUPPORT
#define ASGN3_SUPPORT

#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void *malloc(size_t size);
void *calloc(size_t nitems, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

#endif
