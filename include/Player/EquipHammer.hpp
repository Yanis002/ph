#pragma once

#include "Player/EquipItem.hpp"
#include "types.h"

class EquipHammer : public EquipItem {
  private:
    /* 00 (base) */
    /* 09 */ unk8 mUnk_09[3];
    /* 0c */ unk8 mUnk_0c[0xc];
    /* 18 */ unk32 mUnk_18;
    /* 1c */ unk8 mUnk_1c;
    /* 1d */ unk8 mUnk_1d;
    /* 1e */ unk8 mUnk_1e[2];
    /* 20 */ unk32 mUnk_20;
    /* 24 */ void* mUnk_24;
    /* 28 */ unk32 mUnk_28;
    /* 2c */

  public:
    EquipHammer();

    /* 04 */ virtual ~EquipHammer() override;
    /* 0c */ virtual ItemFlag GetId() const override;
    /* 10 */ virtual void vfunc_10() override; // func_ov14_0213ee04

    /* 14 */ virtual bool IsUsable(unk32 param1) const override;
    /* 18 */ virtual void vfunc_18() override; // func_ov59_02198e3c
    /* 1c */ virtual void vfunc_1c() override; // func_ov59_02198e58

    /* 2c */ virtual unk32 vfunc_2c() override; // func_ov59_02198fcc
    /* 30 */ virtual void vfunc_30() override; // func_ov59_02198e6c
    /* 38 */ virtual void vfunc_38(unk32 param1) override; // func_0v59_02198fc8
    /* 3c */ virtual bool vfunc_3c(Vec4p* param1) const override; // func_ov14_0213ee10
    /* 4c */ virtual s32 vfunc_4c() const override; // func_ov14_0213eea8
    /* 50 */
};
