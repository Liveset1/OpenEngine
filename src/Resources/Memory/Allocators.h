#ifndef OPENENGINE_ALLOCATORS_H
#define OPENENGINE_ALLOCATORS_H

#include <memory.h>
#include <stdbool.h>

typedef struct PoolAlloc {
    size_t elementSize;       // Size of each element in the pool
    size_t elementCount;      // Total number of elements in the pool
    void** freeList;          // Stack of free blocks
    size_t freeIndex;         // Points to the top of the free stack
    void* memory;             // The actual memory block
    bool canAllocate;         // Indicates if the allocator has free space
} PoolAlloc;

bool isSpaceAvailableInPool(PoolAlloc *alloc) {
   return alloc->canAllocate;
}

//typedef struct StackAlloc {
//    char* buffer;   // Pointer to the start of the memory block.
//    size_t top;     // Points to the top of the stack.
//    size_t maxSize; // Maximum size of the allocator.
//} StackAlloc;

#endif //OPENENGINE_ALLOCATORS_H
