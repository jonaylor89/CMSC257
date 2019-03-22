/******************************
 *
 * John Naylor
 * CMSC 257 Assignment
 * Remake malloc
 * asgn3_support.c
 *
 ******************************/

#include "asgn3_support.h"

static void *global_base = NULL;

/*************************************************
 * Get the meta data from the allocated block
 ************************************************/
static struct block_meta *get_block_ptr(void *ptr) {
  return (struct block_meta *)ptr - 1;
}

/*******************************************************
 * Request space from the top of the heap
 ******************************************************/
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

  // Align block to multiple of 8
  block->size = size + (size % 8);
  block->next = NULL;
  block->free = 0;
  block->magic = 0x12345678;

  return block;
}

/*********************************************************************
 * Check if there is any freed space that can be used inside the list
 *********************************************************************/
static struct block_meta *find_free_block(struct block_meta **last, size_t size) {

  struct block_meta *current = global_base;
  
  size_t difference = current->size - size;
  
  while (current != NULL) {
    if ((current->free) && (current->size >= size) && (current->size - size > difference)) {
      difference = current->size - size;
    }

    *last = current;
    current = current->next;

  }

  current = global_base;

  while (current != NULL) {
    if (current->size - size == difference) {
        break;
    }
    *last = current;
    current = current->next;
  }

  return current;
}

/****************************************************************
 * Merge two blocks together
 ****************************************************************/
static void merge_free_blocks(struct block_meta *first, struct block_meta *second) {
  if (first < second) {
    first->size += second->size + META_SIZE; 
    second->next->prev = first;
    first->next = second->next;
  } else {
    second->size += first->size + META_SIZE;
    first->next->prev = second;
    second->next = first->next;
  }
}

/************************************************************
 * Check if there are any blocks next a block that are free
 ***********************************************************/
static void check_adjecent_frees(struct block_meta *block) {
  if (block->free != 1) {
    return; 
  }

  if (block->next != NULL && block->next->free == 1) {
    merge_free_blocks(block, block->next);
  }

  if (block->next != NULL && block->prev->free == 1) {
    merge_free_blocks(block->prev, block);
  }
}

/*****************************************************
 * Split a block into two blocks
 *****************************************************/
static void split_block(struct block_meta *block, int size) {
  // Make sure it's a multiple of 8
  size += size % 8;

  // save old size
  int temp_size = block->size;

  // Change size of original block
  block->size = size;

  void *temp_ptr = (void *)block;

  // Move pointer to the start of the new meta_block
  temp_ptr += (META_SIZE + size);

  struct block_meta *new_block = (struct block_meta *)temp_ptr;

  new_block->size = temp_size - META_SIZE;
  new_block->next = block->next;
  new_block->prev = block;
  new_block->free = 1;
  new_block->magic = 0x12345678;

  block->next = new_block;

}

/***************************************************************
 * Allocate memory of a certain size and return a pointer to it
 ***************************************************************/
void *malloc(size_t size) {

  struct block_meta *block;

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

        // Check if block size can be split then split it
        if (block->size - (size + META_SIZE) > 8) {
            split_block(block, size);
        }

        block->free = 0;
        block->magic = 0x77777777;
      }
    }
  }

  return block + 1;

}

/*************************************************
 * Allocate n number of items and 0 them out
 ************************************************/
void *calloc(size_t nitems, size_t size) {

  size_t total_size = nitems * size; // TODO: check for overflow
  void *ptr = malloc(total_size);
  memset(ptr, 0, total_size);

  return ptr;
}

/****************************************
 * Reallocate a block of memory
 ***************************************/
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

/*****************************
 * Free memory for future use
 ****************************/
void free(void *ptr) {
  if (!ptr) {
    return; 
  }

  struct block_meta *block_ptr = get_block_ptr(ptr);
  block_ptr->free = 1;
  block_ptr->magic = 0x55555555;

  check_adjecent_frees(block_ptr);
}

/***********************************
 * Give me the global_base pointer
 *********************************/
void *getGlobalBase() {
  return global_base;
}





