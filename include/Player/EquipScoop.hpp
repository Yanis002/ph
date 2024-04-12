#pragma once

#include "Player/EquipItem.hpp"
#include "types.h"

class EquipScoop : public EquipItem {
  private:
    /* 0 (base) */
    /* 9 */ unk8 mUnk_9[3];
    /* c */

  public:
    /* 00 */ virtual void vfunc_00() override; // func_ov54_02198d00
    /* 04 */ virtual ~EquipScoop() override;
    /* 0c */ virtual ItemFlag GetId() const override;

    /* 14 */ virtual bool IsUsable(unk32 param1) const override;
    /* 18 */ virtual void vfunc_18() override; // func_0v54_02198d2c

    /* 30 */ virtual void vfunc_30() override; // func_ov54_02198e04
    /* 38 */ virtual void vfunc_38(unk32 param1) override; // func_ov54_02198e4c
    /* 40 */ virtual unk32 vfunc_40() const override; // func_ov54_02198d30
    /* 44 */ virtual unk32 vfunc_44(unk32 param1) const override; // func_ov54_02198d38
    /* 48 */ virtual unk32 vfunc_48(unk32 param1) const override; // func_ov54_02198d48
    /* 50 */
};
