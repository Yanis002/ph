#include "Player/LinkStateBase.hpp"

LinkStateBase *GetLinkState(LinkStateId index) {
    return gLinkStates[index];
}
