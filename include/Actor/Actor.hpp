#pragma once

#include "global.h"
#include "types.h"

#include "lib/math.h"

#include "Physics/Cylinder.hpp"
#include "Physics/Transform.hpp"

class Actor {
  public:
    /* 000 (vtable) */
    /* 004 */ unk32 mType;
    /* 008 */ unk32 mId;
    /* 00c */ unk32 mIndex;
    /* 010 */ unk8 mUnk_010;
    /* 011 */ unk8 mUnk_011;
    /* 012 */ unk16 mUnk_012;
    /* 014 */ unk32 mUnk_014;
    /* 018 */ unk32 mUnk_018;
    /* 01c */ unk32 mUnk_01c;
    /* 020 */ unk32 mUnk_020;
    /* 024 */ unk8 mUnk_024[0x10];
    /* 034 */ unk32 mUnk_034;
    /* 038 */ unk32 mUnk_038;
    /* 03c */ unk32 mUnk_03c;
    /* 040 */ unk32 mUnk_040;
    /* 044 */ unk32 mUnk_044;
    /* 048 */ Vec3p mPos;
    /* 054 */ Vec3p mPrevPos;
    /* 060 */ Vec3p mVel;
    /* 06c */ unk32 mUnk_06c;
    /* 070 */ unk32 mUnk_070;
    /* 074 */ unk32 mUnk_074;
    /* 078 */ unk16 mUnk_078;
    /* 07a */ unk16 mUnk_07a;
    /* 07c */ Cylinder mHitbox;
    /* 08c */ Cylinder mUnk_08c;
    /* 09c */ unk16 mUnk_09c;
    /* 09e */ unk8 mUnk_09e;
    /* 09f */ unk8 mUnk_09f;
    /* 0a4 */ unk8 mUnk_0a4[0x4];
    /* 0a8 */ unk32 mUnk_0a8;
    /* 0ac */ unk32 mUnk_0ac;
    /* 0b0 */ unk32 mUnk_0b0;
    /* 0b4 */ unk32 mUnk_0b4;
    /* 0b8 */ unk8 mUnk_0b8[0x24];
    /* 0dc */ unk16 mUnk_0dc;
    /* 0de */ unk16 mUnk_0de;
    /* 0e0 */ unk16 mUnk_0e0;
    /* 0e2 */ unk16 mUnk_0e2;
    /* 0e4 */ unk16 mUnk_0e4;
    /* 0e6 */ unk8 mUnk_0e6[0x20];
    /* 106 */ unk8 mUnk_106;
    /* 107 */ unk8 mUnk_107;
    /* 108 */ unk8 mUnk_108;
    /* 109 */ unk8 mUnk_109;
    /* 10a */ unk8 mUnk_10a[0x6];
    /* 110 */ unk8 mUnk_110;
    /* 111 */ unk8 mUnk_111;
    /* 112 */ unk8 mUnk_112;
    /* 113 */ unk8 mUnk_113;
    /* 114 */ unk8 mUnk_114;
    /* 115 */ unk8 mUnk_115;
    /* 116 */ unk8 mUnk_116;
    /* 117 */ unk8 mUnk_117;
    /* 118 */ bool mAlive;
    /* 119 */ unk8 mUnk_119;
    /* 11a */ bool mVisible;
    /* 11b */ unk8 mUnk_11b;
    /* 11c */ unk8 mUnk_11c;
    /* 11d */ unk8 mUnk_11d;
    /* 11e */ q4 yOffset;
    /* 120 */ s16 mUnk_120;
    /* 122 */ unk16 mUnk_122;
    /* 124 */ unk8 mUnk_124;
    /* 125 */ unk8 mUnk_125;
    /* 126 */ unk16 mUnk_126;
    /* 128 */ bool mUnk_128;
    /* 129 */ unk8 mUnk_129;
    /* 12a */ unk8 mUnk_12a;
    /* 12b */ unk8 mUnk_12b;
    /* 12c */ unk32 mUnk_12c;
    /* 130 */ unk32 mUnk_130;
    /* 134 */ unk32 mUnk_134;
    /* 138 */ unk32 mUnk_138;
    /* 13c */ unk32 mUnk_13c;
    /* 140 */ unk32 mUnk_140;
    /* 144 */ unk32 mUnk_144;
    /* 148 */

    Actor();

    /* 00 */ virtual ~Actor();
    /* 08 */ virtual bool vfunc_08();
    /* 0c */ virtual void vfunc_0c();
    /* 10 */ virtual void vfunc_10();
    /* 14 */ virtual void vfunc_14(u32 param1);
    /* 18 */ virtual void vfunc_18(u32 param1);
    /* 1c */ virtual void vfunc_1c(u16 param1);
    /* 20 */ virtual void vfunc_20(s32 param1);
    /* 24 */ virtual void vfunc_24();
    /* 28 */ virtual void vfunc_28();
    /* 2c */ virtual s32 vfunc_2c();
    /* 30 */ virtual unk32 vfunc_30();
    /* 34 */ virtual void GetOffsetPos(Vec3p* pos);
    /* 38 */ virtual unk32 vfunc_38();
    /* 3c */ virtual bool CollidesWithLink();
    /* 40 */ virtual bool IsHitboxTouched(bool param1);
    /* 44 */ virtual bool CollidesWith(const Actor* other);
    /* 48 */ virtual bool vfunc_48();
    /* 4c */ virtual bool vfunc_4c(unk32* param1);
    /* 50 */ virtual Vec3p* GetPos();
    /* 54 */ virtual void vfunc_54();
    /* 58 */ virtual void SetUnk_11b();
    /* 5c */ virtual bool SetVelocity(Vec3p* vel);
    /* 60 */ virtual bool vfunc_60();
    /* 64 */ virtual void vfunc_64();
    /* 68 */ virtual void vfunc_68();
    /* 6c */ virtual bool vfunc_6c();
    /* 70 */ virtual bool vfunc_70();
    /* 74 */ virtual void vfunc_74();
    /* 78 */ virtual bool vfunc_78();
    /* 7c */ virtual void vfunc_7c();
    /* 80 */ virtual void vfunc_80();
    /* 84 */ virtual void vfunc_84();
    /* 88 */ virtual void vfunc_88();
    /* 8c */ virtual void vfunc_8c();
    /* 90 */ virtual bool vfunc_90();
    /* 94 */ virtual void vfunc_94();
    /* 98 */ virtual void vfunc_98();
    /* 9c */ virtual void vfunc_9c();
    /* a0 */ virtual bool TrySetTransform(Transform* transform);
    /* a4 */ virtual void SetTransform(Transform* transform);
    /* a8 */ virtual void vfunc_a8();
    /* ac */ virtual void vfunc_ac();
    /* b0 */ virtual void vfunc_b0();
    /* b4 */
};
