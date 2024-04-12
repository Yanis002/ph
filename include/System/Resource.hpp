#pragma once

#include "global.h"
#include "types.h"

typedef void (*ResourceCleanupFunc)(void* object);

struct Resource {
    /* 0 */ Resource* next;
    /* 4 */ ResourceCleanupFunc cleanup;
    /* 8 */ void* object;
    /* c */
};
