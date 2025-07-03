#pragma once

#include "global.h"
#include "nds/math.h"
#include "types.h"

struct UnkStruct_027e0d38_UnkC {
    /* 00 */ unk32 mUnk_00;

    s32 func_ov000_020a5e9c(void);
};

// This might be FlagsUnk2
struct UnkStruct_02082348 {
    /* 00 */ UnkStruct_027e0d38_UnkC mUnk_00;
    /* 04 */ unk32 mUnk_04;
    /* 08 */ unk32 mUnk_08;
    /* 0c */ unk32 mUnk_0c;
    /* 10 */ unk16 mUnk_10;
    /* 12 */ u8 mUnk_12;
    /* 13 */ u8 mUnk_13;
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 16 */
};

struct UnkStruct_027e0d38_Unk28 {
    /* 00 */ unk32 mUnk_00;
    /* 04 */ unk32 mUnk_04;
    /* 08 */ unk32 mUnk_08;
    /* 0C */ unk32 mUnk_0c;
    /* 10 */ unk32 mUnk_10;
    /* 14 */ unk32 mUnk_14;
    /* 18 */ unk32 mUnk_18;
    /* 1C */ UnkStruct_027e0d38_UnkC mUnk_1c;
    /* 20 */ unk32 mUnk_20;
    /* 24 */ unk32 mUnk_24;
    /* 28 */ unk32 mUnk_28;
    /* 2C */ unk8 mUnk_2c;
    /* 2D */ unk8 mUnk_2d;
    /* 2E */ u8 mUnk_2e;
    /* 2F */ unk8 mUnk_2f;
    /* 30 */ unk32 mUnk_30;
    /* 34 */ bool mUnk_34;
    /* 35 */ unk8 mUnk_35;
    /* 36 */ unk16 mUnk_36;
    /* 38 */ Vec3p mUnk_38;
    /* 44 */ UnkStruct_027e0d38_UnkC mUnk_44;
    /* 48 */ unk8 mUnk_48[0x50 - 0x48];
    /* 50 */ unk8 mUnk_50;
    /* 51 */ unk8 mUnk_51;
    /* 52 */ unk8 mUnk_52;
    /* 53 */ unk8 mUnk_53;
    /* 54 */ unk8 mUnk_54;
    /* 55 */ unk8 mUnk_55;
    /* 56 */ u8 mUnk_56;
    /* 57 */ unk8 mUnk_57;
    /* 58 */ unk32 mUnk_58;
    /* 5c */ Vec3p mUnk_5c;
    /* 68 */ unk16 mUnk_68;
    /* 6a */ unk8 mUnk_6a;
    /* 6b */ unk8 mUnk_6b;
    /* 6c */ unk32 mUnk_6c;
    /* 70 */ UnkStruct_02082348 mUnk_70;
};

struct UnkStruct_027e0d38 {
    /* 00 */ unk8 mUnk_00;
    /* 01 */ unk8 mUnk_01[3]; // padding?
    /* 04 */ unk32 mUnk_04;
    /* 08 */ unk32 mUnk_08;
    /* 0c */ UnkStruct_027e0d38_UnkC mUnk_0c;
    /* 10 */ unk32 mUnk_10;
    /* 14 */ unk32 mUnk_14;
    /* 18 */ unk32 mUnk_18;
    /* 1c */ unk16 mUnk_1c;
    /* 1e */ unk8 mUnk_1e;
    /* 1f */ unk8 mUnk_1f;
    /* 20 */ unk8 mUnk_20;
    /* 21 */ unk8 mUnk_21;
    /* 22 */ unk8 mUnk_22[2]; // padding?
    /* 24 */ void *mUnk_24;
    /* 28 */ UnkStruct_027e0d38_Unk28 *mUnk_28;
    /* 2c */

    s32 func_ov000_02078b40();
    unk8 func_ov000_02078b64();
    bool func_ov000_02078b88();
};

extern UnkStruct_027e0d38 *data_027e0d38;
