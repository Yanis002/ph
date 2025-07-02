#include "Actor/Navi/ActorWisdomNavi.hpp"

#pragma section sbss begin
ActorType ActorWisdomNavi::gType = ActorType(ActorTypeId_WisdomNavi, (ActorCreateFunc) ActorWisdomNavi::Create, NULL);
#pragma section sbss end

extern u32 **data_027e0fe0[];
ARM ActorWisdomNavi *ActorWisdomNavi::Create() {
    return new(*data_027e0fe0[0], 4) ActorWisdomNavi();
}

ARM FairyId ActorWisdomNavi::GetFairyId() {
    return FairyId_Wisdom;
}
