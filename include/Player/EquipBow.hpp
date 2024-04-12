#pragma once

#include "Player/EquipItem.hpp"
#include "types.h"

class EquipBow : public EquipItem {
  private:
    /* 00 (base) */
    /* 09 */ unk8 mUnk_09;
    /* 0a */ unk8 mUnk_0a;
    /* 0b */ unk8 mUnk_0b;
    /* 0c */ unk8 mUnk_0c;
    /* 0d */ unk8 mUnk_0d[3];
    /* 10 */

  public:
    EquipBow();

    /* 00 */ virtual void vfunc_00() override; // func_ov56_02198d00
    /* 04 */ virtual ~EquipBow() override;
    /* 0c */ virtual ItemFlag GetId() const override;

    /* 14 */ virtual bool IsUsable(unk32 param1) const override;
    /* 18 */ virtual void vfunc_18() override; // func_ov56_02198d84

    /* 30 */ virtual void vfunc_30() override; // func_ov56_02198de4
    /* 38 */ virtual void vfunc_38(unk32 param1) override; // func_ov56_02198df8
    /* 50 */
};
