#pragma once

#include "global.h"
#include "types.h"

#include "Item/Item.hpp"
#include "System/SysNew.hpp"

class EquipItem : public SysObject {
  private:
    /* 0 (vtable) */
    /* 4 */ u16 mUnk_00;
    /* 6 */ u16 mUnk_04;
    /* 8 */ bool mInUse;

  public:
    EquipItem();

    /* 00 */ virtual void vfunc_00(); // func_ov00_020be8dc
    /* 04 */ virtual ~EquipItem();
    /* 0c */ virtual ItemFlag GetId() const = 0;
    /* 10 */ virtual void vfunc_10(); // func_ov04_0210ba88

    u16 GetAmmo();
    /* 14 */ virtual bool IsUsable(unk32 param1) const;
    /* 18 */ virtual void vfunc_18() = 0;
    /* 1c */ virtual void vfunc_1c(); // func_ov00_020be8e0
    /* 20 */ virtual void GiveAmmo(u32 amount);

    /* 24 */ virtual bool IsInUse() const;
    /* 28 */ virtual bool UpdateInUse(unk32 param1);
    /* 2c */ virtual u32 vfunc_2c(); // func_ov00_020be964
    /* 30 */ virtual void vfunc_30() = 0;
    /* 34 */ virtual void vfunc_34(unk16* param1); // func_ov00_020be96c
    /* 38 */ virtual void vfunc_38(unk32 param1) = 0;
    /* 3c */ virtual bool vfunc_3c(Vec4p* param1) const; // func_ov00_020beb90
    /* 40 */ virtual unk32 vfunc_40() const; // func_ov00_020be970
    /* 44 */ virtual unk32 vfunc_44(unk32 param1) const; // func_ov00_020be978
    /* 48 */ virtual unk32 vfunc_48(unk32 param1) const; // func_ov00_020be980
    /* 4c */ virtual s32 vfunc_4c() const; // func_ov00_020be988
    /* 50 */
};
