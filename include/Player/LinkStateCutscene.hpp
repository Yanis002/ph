#pragma once

#include "global.h"
#include "types.h"

#include "lib/math.h"

#include "Item/Item.hpp"
#include "Player/LinkStateBase.hpp"

class LinkStateCutscene : public LinkStateBase {
  public:
    /* 00 (base) */
    /* 0c */ unk8 mUnk_08[0x24]; // non-documented struct
    /* 30 */ void* mUnk_30;
    /* 34 */ s16 mUnk_34;
    /* 36 */ unk8 mUnk_36[2];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s16 mUnk_3c;
    /* 3e */ unk16 mUnk_3e;
    /* 40 */ Vec3p mUnk_40;
    /* 4c */ Vec3p mUnk_4c;
    /* 58 */ unk32 mUnk_58;
    /* 5c */ unk32 mUnk_5c;
    /* 60 */ unk32 mUnk_60;
    /* 64 */ unk32 mUnk_64;
    /* 68 */ unk32 mUnk_68;
    /* 6c */ unk16 mUnk_6c;
    /* 6e */ unk8 mUnk_6e[2];
    /* 70 */ unk32 mUnk_70;
    /* 74 */ ItemId mLastItemId;
    /* 78 */ s16 mAngle;
    /* 7a */ unk16 mUnk_7a;
    /* 7c */ unk16 mUnk_7c;
    /* 7e */ unk16 mUnk_7e;
    /* 80 */ unk16 mUnk_80;
    /* 82 */ unk8 mUnk_82[2];
    /* 84 */ void* mUnk_84;
    /* 88 */ unk32 mUnk_88[4];
    /* 98 */ unk32 mUnk_98;
    /* 9c */ void* mUnk_9c;
    /* a0 */ unk32 mUnk_a0;
    /* a4 */ bool mUnk_a4;
    /* a5 */ s8 mUnk_a5;
    /* a6 */ bool mUnk_a6;
    /* a7 */ unk8 mUnk_a7[5];
    /* ac */

    /* 00 */ virtual void vfunc_00() override;
    /* 04 */ virtual ~LinkStateCutscene() override;
    /* 0c */ virtual LinkStateId GetId() override;
    /* 10 */ virtual void CreateDebugHierarchy() override;
    /* 14 */ virtual void OnStateEnter() override;
    /* 18 */ virtual void OnStateLeave(s32 param1) override;
    /* 1c */ virtual void vfunc_1c() override;
    /* 24 */ virtual bool vfunc_24(s32 param1) override;
    /* 28 */ virtual bool vfunc_28() override;
    /* 30 */ virtual void vfunc_30(unk32 param1) override;
    /* 38 */ virtual bool vfunc_38() override;
    /* 40 */ virtual bool vfunc_40() override;
    /* 44 */
};
