#pragma once

#include "Player/EquipItem.hpp"
#include "types.h"

class EquipShield {
  private:
    /* 00 (base) */
    /* 09 */ unk8 mUnk_09[7];
    /* 10 */ void* mUnk_10;
    /* 14 */ void* mUnk_14;
    /* 18 */ unk8 mUnk_18[4];
    /* 1c */ void* mUnk_1c;
    /* 20 */ void* mUnk_20;
    /* 24 */ void* mUnk_24;
    /* 28 */ void* mUnk_28;
    /* 2c */

  public:
    EquipShield();

    /* 00 */ virtual void vfunc_00() override; // func_ov00_020c06d4
    /* 04 */ virtual ~EquipShield() override; // func_ov04_0210bc94
    /* 0c */ virtual ItemFlag GetId() const override;
    /* 10 */ virtual void vfunc_10() override; // func_ov00_020c076c

    /* 14 */ virtual bool IsUsable(unk32 param1) const override;
    /* 18 */ virtual void vfunc_18() override; // func_ov00_020c0770
    /* 1c */ virtual void vfunc_1c(); // func_ov00_020c07f8

    /* 30 */ virtual void vfunc_30() override; // func_ov00_020c0804
    /* 38 */ virtual void vfunc_38(unk32 param1) override; // func_ov00_020c086c
    /* 3c */ virtual bool vfunc_3c(Vec4p* param1) const; // func_ov00_020c0a88
    /* 50 */
};
