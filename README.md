
# CMSC 257, Computer Systems

## Current Assignment: 3

TODO:

1. Split blocks when extra is available. 
  - If leftover > META_SIZE + (META_SIZE % 8) then
  - splitBlock()
  - endif

2. Combine free blocks
  - Inside Free:
  - if block->prev->free = 1 then
  - combineBlocks(block, block->prev)
  - endif
  - if block->next->free = 1 then
  - combineBlocks(block, block->next)
  - endif

3. Use best-fit algorithm
  - Google best fit and make it work
