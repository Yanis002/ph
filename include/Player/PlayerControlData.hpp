#pragma once

#include "global.h"
#include "types.h"

#include "lib/math.h"

#include "System/SysNew.hpp"

class PlayerControlData : public SysObject {
  public:
    /* 000 (vtable) */
    /* 004 */ unk32 mUnk_004;
    /* 008 */ unk32 mUnk_008;
    /* 00c */ unk32 mRadius;
    /* 010 */ unk32 mUnk_010;
    /* 014 */ unk32 mUnk_014;
    /* 018 */ unk32 mStateUnk;
    /* 01c */ Vec3p mUnk_01c;
    /* 028 */ unk16 mUnk_028;
    /* 02a */ unk16 mUnk_02a;
    /* 02c */ unk16 mUnk_02c;
    /* 02e */ unk16 mUnk_02e;
    /* 030 */ unk16 mUnk_030;
    /* 032 */ unk16 mUnk_032;
    /* 034 */ Vec3p mFairyVector; // shortened vector from link to fairy?
    /* 040 */ unk8 mUnk_040[0xc0];
    /* 100 */ unk32 mUnk_100;
    /* 104 */ unk8 mUnk_104[0x14];
    /* 118 */ unk32 mUnk_118;
    /* 11c */ unk8 mUnk_11c[4];
    /* 120 */ unk32 mUnk_120;
    /* 124 */ unk8 mUnk_124[0x14];
    /* 138 */ unk32 mUnk_138;
    /* 13c */ unk8 mUnk_13c[4];
    /* 140 */ unk32 mUnk_140;
    /* 144 */ unk32 mUnk_144;
    /* 148 */ unk8 mUnk_148[8];
    /* 150 */ unk16 mUnk_150;
    /* 152 */ unk8 mUnk_152[2];
    /* 154 */ unk32 mUnk_154;
    /* 158 */ unk32 mUnk_158;
    /* 15c */ s32 mUnk_15c;
    /* 160 */ unk32 mUnk_160;
    /* 164 */ s32 mUnk_164;
    /* 168 */ unk32 mUnk_168;
    /* 16c */ unk32 mUnk_16c;
    /* 170 */ unk32 mUnk_170;
    /* 174 */ unk8 mUnk_174[4];
    /* 178 */ unk32 mUnk_178;
    /* 17c */ unk32 mUnk_17c;
    /* 180 */ unk8 mUnk_180[4];
    /* 184 */ unk32 mUnk_184;
    /* 184 */ unk32 mUnk_188;
    /* 18c */ unk32 mUnk_18c;
    /* 190 */ unk32 mUnk_190;
    /* 194 */ unk32 mUnk_194;
    /* 198 */ unk32 mUnk_198;
    /* 19c */ unk16 mUnk_19c;
    /* 19e */ unk16 mUnk_19e;
    /* 1a0 */
};
