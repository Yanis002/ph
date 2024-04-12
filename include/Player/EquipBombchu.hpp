#pragma once

#include "Player/EquipItem.hpp"
#include "types.h"

class EquipBombchu : public EquipItem {
  private:
    /* 00 (base) */
    /* 09 */ u8 mUnk_09[3];
    /* 0c */ u8 mUnk_0c[0x0c];
    /* 18 */ u32 mUnk_18;
    /* 1c */ void* mUnk_1c;
    /* 20 */ void* mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ void* mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u8 mUnk_38[0xc];
    /* 44 */ u16 mUnk_44;
    /* 46 */ u8 mUnk_46;
    /* 47 */ char mUnk_47;
    /* 48 */ bool mUnk_48;
    /* 49 */ unk8 mUnk_49[3];
    /* 4c */

  public:
    EquipBombchu();

    /* 00 */ virtual void vfunc_00() override; // func_ov58_02198fc0
    /* 04 */ virtual ~EquipBombchu() override;
    /* 0c */ virtual ItemFlag GetId() const override;

    bool CheckUsable(unk32 param1) const;
    /* 14 */ virtual bool IsUsable(unk32 param1) const override;
    /* 18 */ virtual void vfunc_18() override; // func_ov58_0219903c
    /* 1c */ virtual void vfunc_1c() override; // func_ov58_02199060

    /* 30 */ virtual void vfunc_30() override; // func_ov58_0219906c
    /* 34 */ virtual void vfunc_34(unk16* param1) override; // func_ov58_0213ecb4
    /* 38 */ virtual void vfunc_38(unk32 param1) override; // func_ov58_02199170
    /* 50 */
};
