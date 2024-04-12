#pragma once

#include "Player/EquipItem.hpp"
#include "types.h"

class EquipPotion : public EquipItem {
  private:
    /* 00 (base) */
    /* 09 */ unk8 mUnk_09[3];
    /* 0c */ unk32 mUnk_0c;
    /* 10 */

  public:
    EquipPotion();

    /* 00 */ virtual void vfunc_00() override; // func_ov55_021991a8
    /* 04 */ virtual ~EquipPotion() override;

    /* 14 */ virtual bool IsUsable(unk32 param1) const override;
    /* 18 */ virtual void vfunc_18() override; // func_ov55_021991ac
    /* 1c */ virtual void vfunc_1c() override; // func_ov55_021991b0

    /* 30 */ virtual void vfunc_30() override; // func_ov55_02199274
    /* 38 */ virtual void vfunc_38(unk32 param1) override; // func_0v55_02199278
    /* 50 */
};

class EquipPotionA : public EquipPotion {
  public:
    EquipPotionA();

    /* 04 */ virtual ~EquipPotionA() override;
    /* 0c */ virtual ItemFlag GetId() const override;
    /* 50 */
};

class EquipPotionB : public EquipPotion {
  public:
    EquipPotionB();

    /* 04 */ virtual ~EquipPotionB() override;
    /* 0c */ virtual ItemFlag GetId() const override;
    /* 50 */
};
