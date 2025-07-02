#pragma once

#include "global.h"
#include "types.h"

#include "System/SysNew.hpp"
#include "Unknown/UnkStruct_0202e1a0.hpp"

class UnkStruct_ov000_020c0c08 : public SysObject {
public:
    /* 00 (vtable) */
    /* 04 */ unk32 mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ UnkStruct_0202e1a0 mUnk_0c;
    /* 24 */

    /* 00 */ virtual ~UnkStruct_ov000_020c0c08();
    /* 08 */

    UnkStruct_ov000_020c0c08(unk32 param1, u8 *param2);
};
