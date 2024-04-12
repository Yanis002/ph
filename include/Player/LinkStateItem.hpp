#pragma once

#include "global.h"
#include "types.h"

#include "lib/math.h"

#include "Item/Item.hpp"
#include "Player/EquipBombchu.hpp"
#include "Player/LinkStateBase.hpp"
#include "Player/LinkStateMove.hpp"

class LinkStateItem : public LinkStateBase {
  public:
    /* 00 (base) */
    /* 0c */ void* mUnk_0c;
    /* 10 */ unk32 mUnk_10;
    /* 14 */ ItemId mEquipId;
    /* 18 */ ItemId mNextEquip;
    /* 1c */ unk32 mUnk_1c;
    /* 20 */ unk16 mUnk_20;
    /* 22 */ unk8 mUnk_22[2];
    /* 24 */ s8 mUnk_24;
    /* 25 */ unk8 mUnk_25[7];
    /* 2c */ unk16 mUnk_2c;
    /* 2e */ unk8 mUnk_2e[2];
    /* 30 */ void* mUnk_30;
    /* 34 */ unk32 mUnk_34;
    /* 38 */ unk32 mUnk_38;
    /* 3c */ void* mUnk_3c;
    /* 40 */ unk32 mUnk_40;
    /* 44 */ unk32 mUnk_44;
    /* 48 */ void* mUnk_48;
    /* 4c */ unk32 mUnk_4c;
    /* 50 */ unk32 mUnk_50[2];
    /* 58 */ unk32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */

    /* 00 */ virtual void vfunc_00() override;
    /* 04 */ virtual ~LinkStateItem() override;
    /* 0c */ virtual LinkStateId GetId() override;
    /* 14 */ virtual void OnStateEnter() override;
    /* 18 */ virtual void OnStateLeave(s32 param1) override;
    /* 1c */ virtual void vfunc_1c() override;
    /* 20 */ virtual bool vfunc_20(s32 param1) override;
    /* 24 */ virtual bool vfunc_24(s32 param1) override;
    /* 28 */ virtual bool vfunc_28() override;
    /* 44 */

    s32 IsHammerEquipped(); // returns 0 if hammer is equipped, otherwise -1
    EquipBombchu* GetEquipBombchu();
    LinkStateMove* GetLinkStateMove();
    bool func_ov00_020abf70();
};
