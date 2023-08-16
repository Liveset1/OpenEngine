#ifndef OPENENGINE_ASSET_MANAGER_H
#define OPENENGINE_ASSET_MANAGER_H

#include <stdio.h>
#include "../Memory/Allocators.h"
#define MAX_POOL_ALLOCATORS 10

void *allocate(size_t objectSize);
int deallocate(void *memory);

#endif // OPENENGINE_ASSET_MANAGER_H
