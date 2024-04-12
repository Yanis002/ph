#pragma once

#include "global.h"
#include "lib/math.h"
#include "types.h"

#include "Player/MotionParams.hpp"
#include "Player/PlayerBase.hpp"

#include "Actor/ActorManager.hpp"

#include "Debug/DebugHierarchy.hpp"

typedef s32 PlayerCharacter;
enum PlayerCharacter_ {
    PlayerCharacter_Link = 0,
    PlayerCharacter_Gongoron = 1,
    PlayerCharacter_COUNT = 2,
};

class PlayerLinkBase : public PlayerBase {
    /* 00 (base) */
    /* 14 */ Vec3p mPos;
    /* 20 */ Vec3p mVel;
    /* 2c */ unk8 mTilePos[2][PlayerCharacter_COUNT];
    /* 30 */ unk32 mAltitude;
    /* 34 */ unk8 mUnk_34[4];
    /* 38 */ s32 mUnk_38;
    /* 3c */ ActorRef mGrabActor;
    /* 44 */ s32 mUnk_44;
    /* 48 */ unk16 mUnk_48;
    /* 4a */ unk16 mUnk_4a;
    /* 4c */ unk32 mUnk_4c;
    /* 50 */ unk32 mUnk_50;
    /* 54 */ s16 mUnk_54;
    /* 56 */ unk16 mUnk_56;
    /* 58 */ unk16 mUnk_58;
    /* 5a */ s16 mUnk_5a;
    /* 5c */ unk8 mUnk_5c[3];
    /* 5f */ bool mUnk_5f;
    /* 60 */ MotionParams* mMotionParams;
    /* 64 */ DebugHierarchy* mDebugHierarchy_0;
    /* 68 */ DebugHierarchy* mDebugHierarchy_1;
    /* 6c */ DebugHierarchy* mDebugHierarchy_2;
    /* 70 */

    /* 00 */ s32 GetMaxHealth() override;
    /* 08 */ ItemFlag GetEquipId() override;
    /* 0c */ bool CanMove() override;
    /* 10 */ void vfunc_10(Cylinder* param1) override;
    /* 14 */ void vfunc_14(Cylinder* param1) override;
    /* 18 */ void vfunc_18(s32 param1) override;
    /* 1c */ void Init() override;
    /* 20 */ void vfunc_20() override;
    /* 24 */ void vfunc_24() override;
    /* 28 */ void vfunc_28(s32 param1) override;
    /* 2c */ void vfunc_2c(s32 param1, unk8 param2) override;
    /* 30 */ void vfunc_30(s32 param1, Vec3p* param2, s32 param3) override;
    /* 34 */ bool Teleport(Vec3p* pos, s16 angle, unk32 param3, bool param4, bool param5) override;
    /* 38 */ bool TeleportToEntrance(unk32 entranceId, bool param2) override;
    /* 3c */ bool TeleportToLastEntrance(bool param1) override;
    /* 50 */ ~PlayerLinkBase() override;
    /* 58 */ virtual bool vfunc_58();
    /* 5c */ virtual bool vfunc_5c();
    /* 60 */ virtual bool vfunc_60();
    /* 64 */ virtual void vfunc_64();
    /* 68 */ virtual void vfunc_68();
    /* 6c */ virtual void vfunc_6c();
    /* 70 */ virtual void vfunc_70(s32 param1, Vec3p* param2, unk32 param3);
    /* 74 */ virtual void vfunc_74();
    /* 78 */ virtual bool vfunc_78();
    /* 7c */ virtual void vfunc_7c();
    /* 80 */ virtual void SetUnk_5e();
    /* 84 */ virtual void ResetUnk_5e();
    /* 88 */
};
