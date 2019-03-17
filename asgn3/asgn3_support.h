
#ifndef ASGN3_SUPPORT
#define ASGN3_SUPPORT

#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define META_SIZE sizeof(struct block_meta)


struct block_meta {
  size_t size;
  struct block_meta *next;
  struct block_meta *prev;
  int free;
  int magic;
};

void *malloc(size_t size);
void *calloc(size_t nitems, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

void *getGlobalBase();

#endif
