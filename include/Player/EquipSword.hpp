#pragma once

#include "Player/EquipItem.hpp"
#include "types.h"

class EquipSword : public EquipItem {
  private:
    /* 00 (base) */
    /* 09 */ unk8 mUnk_09[3]; // padding?
    /* 0c */ void* mUnk_0c;
    /* 10 */ void* mUnk_10;
    /* 14 */ void* mUnk_14;
    /* 18 */ void* mUnk_18;
    /* 1c */ void* mUnk_1c;
    /* 20 */ void* mUnk_20;
    /* 24 */ void* mUnk_24;
    /* 28 */ void* mUnk_28;
    /* 2c */ unk32 mUnk_2c;
    /* 30 */ unk32 mUnk_30;
    /* 34 */ unk32 mUnk_34;
    /* 38 */ unk8 mUnk_38[8];
    /* 40 */ void* mUnk_40;
    /* 44 */ unk32 mUnk_44;
    /* 48 */ unk32 mUnk_48;
    /* 4c */ unk32 mUnk_4c;
    /* 50 */ unk32 mUnk_50;
    /* 54 */ unk16 mUnk_54;
    /* 56 */ unk16 mUnk_56;
    /* 58 */ unk16 mUnk_58;
    /* 5a */ unk16 mUnk_5a;
    /* 5c */ unk16 mUnk_5c;
    /* 5e */ unk8 mUnk_5e[2];
    /* 60 */ unk32 mUnk_60;
    /* 64 */ unk32 mUnk_64;
    /* 68 */ void* mUnk_68;
    /* 6c */ unk8 mUnk_6c[2];
    /* 6e */ unk8 mUnk_6e;
    /* 6f */ unk8 mUnk_6f;
    /* 70 */

  public:
    EquipSword();

    /* 00 */ virtual void vfunc_00() override; // func_ov00_020beffc
    /* 04 */ virtual ~EquipSword() override;
    /* 0c */ virtual ItemFlag GetId() const override;
    /* 10 */ virtual void vfunc_10() override; // func_ov00_020bf18c

    /* 18 */ virtual void vfunc_18() override; // func_ov00_020bf270
    /* 1c */ virtual void vfunc_1c() override; // func_ov00_020bf2d8

    /* 28 */ virtual bool UpdateInUse(unk32 param1) override;
    /* 2c */ virtual u32 vfunc_2c() override; // func_ov00_020c0674
    /* 30 */ virtual void vfunc_30() override; // func_ov00_020bf538
    /* 38 */ virtual void vfunc_38(unk32 param1) override; // func_ov00_020bff94
    /* 3c */ virtual bool vfunc_3c(Vec4p* param1) const override; // func_ov00_020c01dc
    /* 50 */
};
