#pragma once

#include "Actor/Actor.hpp"
#include "Actor/ActorType.hpp"
#include "Item/ItemManager.hpp"
#include "global.h"
#include "nds/math.h"
#include "types.h"

class UnkStruct_020c66bc {
public:
    /* 00 */ unk32 mUnk_00;
    /* 04 */

    UnkStruct_020c66bc();
    ~UnkStruct_020c66bc();

    void func_ov000_020c66e4(Vec3p *param1, u16 param2, unk8 param3, unk32 param4);
};

class ActorFish : public Actor {
public:
    static ActorType gType;

    /* 000 (base) */
    /* 158 */ UnkStruct_020c66bc mUnk_158;
    /* 15C */ unk32 mUnk_15C;
    /* 160 */ unk32 mUnk_160;
    /* 164 */ unk32 mUnk_164;
    /* 168 */ unk32 mUnk_168;
    /* 16C */ unk32 mUnk_16C;
    /* 170 */ unk32 mUnk_170;
    /* 174 */ unk32 mUnk_174;
    /* 178 */ u32 mUnk_178;
    /* 17C */ unk32 mUnk_17C;
    /* 180 */

    /* 00 */ virtual ~ActorFish() override;
    /* 08 */ virtual bool func_ov015_02183cb4(void) override;
    /* 14 */ virtual void func_ov015_02184108(void) override;
    /* 1C */ virtual void func_ov015_0218427c(u16 *param1) override;

    static ActorFish *Create();
    bool func_ov015_02183bc4(void);
    ActorFish();
    void func_ov015_021843c0(void);
};

class ActorFish2 : public ActorFish {
public:
    /* 000 (base) */
    /* 180 */ unk8 mUnk_180[0x11E];
    /* 29e */ unk8 mUnk_29e;
    /* 29e */ unk8 mUnk_29f;
    /* 2a0 */ unk8 mUnk_2a0[0x52];
    /* 2f2 */ unk8 mUnk_2f2;
    /* 2f2 */ unk8 mUnk_2f3;
    /* 2f4 */ unk8 mUnk_2f4[0xA6];
    /* 39a */ unk8 mUnk_39a;
    /* 39a */ unk8 mUnk_39b;
    /* 39c */ unk8 mUnk_39c[0x10d];
    /* 4a9 */ unk8 mUnk_4a9;
    /* 4a9 */ unk8 mUnk_4aa;
    /* 4ab */
};
