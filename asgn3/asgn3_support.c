
#include "asgn3_support.h"

static void *global_base = NULL;

static struct block_meta *get_block_ptr(void *ptr) {
  return (struct block_meta *)ptr - 1;
}

static struct block_meta *request_space(struct block_meta *last, size_t size) {
  struct block_meta *block;
  block = sbrk(0);
  void *request = sbrk(size + META_SIZE);

  if (request == (void *) -1) {
    return NULL; 
  }

  if (last) {
    last->next = block; 
    block->prev = last;
  } else {
    block->prev = NULL; 
  }

  block->size = size + (size % 8);
  block->next = NULL;
  block->free = 0;
  block->magic = 0x12345678;

  return block;
}

static struct block_meta *find_free_block(struct block_meta **last, size_t size) {
  struct block_meta *current = global_base;

  while (current && !(current->free && current->size >= size)) {
    *last = current;
    current = current->next;
  }

  return current;
}

void *malloc(size_t size) {

  struct block_meta *block;
  // TODO: align size

  if (size <= 0) {
    return NULL; 
  }

  if (!global_base) {
    block = request_space(NULL, size);

    if (!block) {
      return NULL; 
    } 

    global_base = block;
  } else {
    struct block_meta *last = global_base;
    block = find_free_block(&last, size);

    if (!block) {
      block = request_space(last, size);

      if (!block) {
        return NULL; 
      } else {
        block->free = 0;
        block->magic = 0x77777777;
      }
    }
  }

  return block + 1;

}

void *calloc(size_t nitems, size_t size) {

  size_t total_size = nitems * size; // TODO: check for overflow
  void *ptr = malloc(total_size);
  memset(ptr, 0, total_size);

  return ptr;
}

void *realloc(void *ptr, size_t size) {

  if (!ptr) {
    return malloc(size);
  }

  struct block_meta *block_ptr = get_block_ptr(ptr);
  if (block_ptr->size >= size) {
    return ptr; 
  }

  void *new_ptr;
  new_ptr = malloc(size);
  if (!new_ptr) {
    return NULL; 
  }

  memcpy(new_ptr, ptr, block_ptr->size);
  free(ptr);

  return new_ptr;
}

void free(void *ptr) {
  if (!ptr) {
    return; 
  }

  struct block_meta *block_ptr = get_block_ptr(ptr);
  block_ptr->free = 1;
  block_ptr->magic = 0x55555555;
}

void *getGlobalBase() {
  return global_base;
}






