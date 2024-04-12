#pragma once

#include "Player/EquipItem.hpp"
#include "types.h"

class EquipRope : public EquipItem {
  private:
    /* 00 (base) */
    /* 09 */ unk8 mUnk_09;
    /* 0a */ unk16 mUnk_0a;
    /* 0c */ unk8 mUnk_0c[4];
    /* 10 */ unk32 mUnk_10;
    /* 14 */ unk32 mUnk_14;
    /* 18 */ unk8 mUnk_18[0x54];
    /* 6c */ unk16 mUnk_6c;
    /* 6e */ unk8 mUnk_6e[2];
    /* 70 */ unk16 mUnk_70;
    /* 72 */ unk8 mUnk_72[0x12];
    /* 84 */ void* mUnk_84;
    /* 88 */ unk8 mUnk_88[0x18];
    /* a0 */ unk32 mUnk_a0;
    /* a4 */

  public:
    EquipRope();

    /* 04 */ virtual ~EquipRope() override;
    /* 0c */ virtual ItemFlag GetId() const override;
    /* 10 */ virtual void vfunc_10() override; // func_ov14_0213d3a0

    u16 GetAmmo();
    /* 14 */ virtual bool IsUsable(unk32 param1) const override;
    /* 18 */ virtual void vfunc_18() override; // func_ov57_021992f4
    /* 1c */ virtual void vfunc_1c() override; // func_ov57_0219935c

    /* 30 */ virtual void vfunc_30() override; // func_ov57_02199744
    /* 38 */ virtual void vfunc_38(unk32 param1) override; // func_ov57_021998f0
    /* 50 */
};
