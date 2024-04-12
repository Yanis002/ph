#pragma once

#include "global.h"
#include "types.h"

#include "Actor/Actor.hpp"

typedef Actor* (*ActorCreateFunc)();

struct ActorType {
    /* 00 */ char type[4];
    /* 04 */ ActorCreateFunc create;
    /* 08 */ unk32 unk_08;
    /* 0c */ unk32 unk_0c;
    /* 10 */ ActorType* next;
    /* 14 */
};
