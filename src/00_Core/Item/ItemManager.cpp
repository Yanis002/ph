#include "Item/ItemManager.hpp"

extern u32* data_027e0ce0[];

THUMB ItemManager* ItemManager::Create() {
    gItemManager = new (data_027e0ce0[1], 4) ItemManager();
    return gItemManager;
}

THUMB void ItemManager::Destroy() {
    delete gItemManager;
    gItemManager = 0;
}

THUMB void ItemManager::ClearPrevEquippedItem() { mPrevEquippedItem = ItemFlag_None; }

THUMB void ItemManager::Save(SaveItemManager* save) {
    save->itemFlags = mItemFlags;
    save->numRupees = mNumRupees;
    for (s32 i = 0; i < NUM_POTIONS; ++i) {
        save->potions[i] = mPotions[i];
    }
    save->numBombs = (u8)(*mAmmo)[ItemFlag_BombBag];
    save->numBombchus = (u8)(*mAmmo)[ItemFlag_BombchuBag];
    save->numArrows = (u8)(*mAmmo)[ItemFlag_Bow];
    save->equippedItem = (u8)mEquippedItem;
    save->salvagedTreasureFlags = mSalvagedTreasureFlags;
    save->hourglassSeconds = FastDivide(mHourglassSandFrames, 60);
    for (s32 i = 0; i < Gem_COUNT; ++i) {
        save->numGems[i] = mNumGems[i];
    }
    for (s32 i = 0; i < ShipPart_COUNT; ++i) {
        save->equippedShipParts[i] = mEquippedShipParts[i];
        for (s32 j = 0; j < ShipType_COUNT; ++j) {
            save->shipParts[i][j] = mShipParts[i][j];
        }
    }
    save->shipPartPricesShown = mShipPartPricesShown;
    for (s32 i = 0; i < Treasure_COUNT; ++i) {
        save->treasure[i] = mTreasure[i];
    }
    save->treasurePriceShownFlags[0] = mTreasurePriceShownFlags[0];
    for (s32 i = 0; i < 6; ++i) {
        save->unk_9f[i] = mUnk_098[i];
        save->unk_82[i] = mUnk_09e[i];
    }
    save->quiverSize = mQuiverSize;
    save->bombBagSize = mBombBagSize;
    save->bombchuBagSize = mBombchuBagSize;
    if (mEquippedFairy == FairyId_None) {
        save->equippedFairy = 3;
        return;
    }
    save->equippedFairy = (u8)mEquippedFairy;
}

THUMB void ItemManager::Load(const SaveItemManager* save) {
    mItemFlags = save->itemFlags;
    mNumRupees = save->numRupees;
    mHourglassSandFrames =
        save->hourglassSeconds <= MAX_HOURGLASS_SECONDS ? save->hourglassSeconds * 60 : MAX_HOURGLASS_SECONDS * 60;
    for (s32 i = ItemFlag_EQUIP_START; i < ItemFlag_EQUIP_END; ++i) {
        if (GET_FLAG(mItemFlags.flags, (u32)i)) {
            (*mAmmo)[i] = 1;
        }
    }
    (*mAmmo)[ItemFlag_BombBag] = save->numBombs;
    (*mAmmo)[ItemFlag_BombchuBag] = save->numBombchus;
    (*mAmmo)[ItemFlag_Bow] = save->numArrows;
    for (s32 i = 0; i < NUM_POTIONS; ++i) {
        mPotions[i] = save->potions[i];
    }
    mEquippedItem = save->equippedItem;
    mSalvagedTreasureFlags = save->salvagedTreasureFlags;
    for (s32 i = 0; i < Gem_COUNT; ++i) {
        mNumGems[i] = save->numGems[i];
    }
    for (s32 i = 0; i < ShipPart_COUNT; ++i) {
        mEquippedShipParts[i] = save->equippedShipParts[i];
        for (s32 j = 0; j < ShipType_COUNT; ++j) {
            mShipParts[i][j] = save->shipParts[i][j];
        }
    }
    mShipPartPricesShown = save->shipPartPricesShown;
    for (s32 i = 0; i < Treasure_COUNT; ++i) {
        mTreasure[i] = save->treasure[i];
    }
    mTreasurePriceShownFlags[0] = save->treasurePriceShownFlags[0];
    for (s32 i = 0; i < 6; ++i) {
        mUnk_098[i] = save->unk_9f[i];
        mUnk_09e[i] = save->unk_82[i];
    }
    mQuiverSize = save->quiverSize;
    mBombBagSize = save->bombBagSize;
    mBombchuBagSize = save->bombchuBagSize;
    mEquippedFairy = save->equippedFairy;
    if (mEquippedFairy >= FairyId_COUNT) {
        mEquippedFairy = FairyId_None;
    }
    if ((u32)mEquippedItem - 9 <= 1) {
        if (this->HasItem(ItemFlag_Boomerang)) {
            mEquippedItem = ItemFlag_Boomerang;
        } else {
            mEquippedItem = ItemFlag_None;
        }
    } else if (mEquippedItem == ItemFlag_None) {
        if (this->HasItem(ItemFlag_Boomerang)) {
            mEquippedItem = ItemFlag_Boomerang;
        }
    }
}

ARM FairyId ItemManager::GetEquippedFairy() const {
    FairyId fairy = mEquippedFairy;
    if (fairy == FairyId_None)
        return FairyId_Courage;
    return fairy;
}

ARM ActorNavi* ItemManager::GetFairy(FairyId id) const { return mFairies[id]; }

extern UnkStruct_027e0d38* data_027e0d38;
extern unk32 gPlayerAnimHandler;
extern "C" void LoadEquipItemModel(unk32 param1, ItemFlag param2);
extern "C" void _ZNK11ItemManager15GetEquippedItemEv();
extern "C" void _ZN14OverlayManager13LoadEquipItemEi();
ARM void ItemManager::TickEquipItem(void) {
    ItemFlag equip = this->GetEquippedItem();
    if (mEquipLoadTimer != 0) {
        mEquipLoadTimer -= 1;
        if (mEquipLoadTimer == 0 && equip != ItemFlag_None && data_027e0d38->mUnk_14 != 1) {
            gOverlayManager.LoadEquipItem(equip);
            LoadEquipItemModel(gPlayerAnimHandler, equip);
            (*mEquipItems)[equip]->vfunc_00();
        }
    }
    (*mEquipItems)[ItemFlag_OshusSword]->vfunc_30();
    (*mEquipItems)[ItemFlag_WoodenShield]->vfunc_30();
    if (data_027e0d38->mUnk_14 == 1)
        return;
    if (equip != ItemFlag_None && mEquipLoadTimer == 0) {
        (*mEquipItems)[equip]->vfunc_30();
    }
}

ARM void ItemManager::func_ov00_020ad528() {}

ARM ItemModel* ItemManager::GetItemModel(ItemModelId id) { return mItemModels[id]; }

extern unk32 data_027e0fc4;
extern "C" void* func_ov00_020bb3a8(unk32 param1, u32 index);
extern "C" void func_ov00_020c0bdc(void* param1, unk32 param2);
ARM void ItemManager::func_ov00_020ad538(unk32 param1) const {
    void* unk1 = func_ov00_020bb3a8(data_027e0fc4, 6);
    func_ov00_020c0bdc(unk1, param1);
}

ARM void ItemManager::func_ov00_020ad560(unk32 param1) const {
    void* unk1 = func_ov00_020bb3a8(data_027e0fc4, 7);
    func_ov00_020c0bdc(unk1, param1);
}

ARM ItemModel* ItemManager::GetDungeonItemModel(u32 index) { return mDungeonItemModels[index]; }

ARM void ItemManager::func_ov00_020ad594(unk32 param1) const {
    void* unk1 = func_ov00_020bb3a8(data_027e0fc4, 11);
    func_ov00_020c0bdc(unk1, param1);
}

ARM void ItemManager::Sword_vfunc_38(unk32 param1) { (*mEquipItems)[ItemFlag_OshusSword]->vfunc_38(param1); }

ARM void ItemManager::Shield_vfunc_38(unk32 param1) { (*mEquipItems)[ItemFlag_WoodenShield]->vfunc_38(param1); }

extern unk32 data_027e0618;
ARM void ItemManager::EquipItem_vfunc_38(unk32 param1) {
    if (data_027e0618 != 6) {
        this->Sword_vfunc_38(param1);
        this->Shield_vfunc_38(param1);
    }
    if (data_027e0d38->mUnk_14 == 1)
        return;

    ItemFlag equip = this->GetEquippedItem();
    if (equip == ItemFlag_None)
        return;
    if (mEquipLoadTimer > 0)
        return;

    (*mEquipItems)[equip]->vfunc_38(param1);
}

ARM bool ItemManager::EquipItem_vfunc_3c(Vec4p* param1, ItemFlag equipId) {
    Vec4p result;
    if ((*mEquipItems)[equipId]->vfunc_3c(&result)) {
        s32 step = (*mEquipItems)[equipId]->vfunc_4c();
        if (step > 0) {
            Approach_thunk(&result.y, param1->y, step);
        }
        return func_01ffec34(param1, &result);
    }
    return false;
}

ARM void ItemManager::EquipItem_vfunc_2c(ItemFlag equipId) { (*mEquipItems)[equipId]->vfunc_2c(); }

ARM EquipItem* ItemManager::GetEquipItem(ItemFlag equipId) {
    if (equipId == ItemFlag_None) {
        return NULL;
    } else {
        return (*mEquipItems)[equipId];
    }
}

ARM u16 ItemManager::GetAmmo(ItemFlag equipId) const { return (*mAmmo)[equipId]; }

ARM void ItemManager::GiveAmmo(ItemFlag equipId, u16 amount) {
    (*mAmmo)[equipId] += amount;
    if ((*mAmmo)[equipId] <= this->GetMaxAmmo(equipId))
        return;
    (*mAmmo)[equipId] = this->GetMaxAmmo(equipId);
}

extern "C" unk32 func_ov00_02078b40(UnkStruct_027e0d38* param1);
extern void* data_027e10a4;
extern "C" bool func_ov15_02136670(void* param1);
extern unk8 data_ov29_0217a4ac[];
extern void* data_027e0e60;
extern "C" bool func_ov00_020849f8(void* param1);
extern unk32 data_027e0fc8;
extern "C" bool func_ov00_020bbd80(unk32 param1, unk32 param2);
extern "C" bool _ZNK11ItemManager7HasItemEi();
extern "C" void _ZN11ItemManager12GetEquipItemEi();
ARM bool NONMATCH(ItemManager::func_ov00_020ad790)(unk32 param1) {
#ifndef NONMATCHING
#include "../asm/ov00/Item/ItemManager_func_ov00_020ad790.inc"
#else
    unk32 unk1 = func_ov00_02078b40(data_027e0d38);
    if (unk1 == 2)
        return func_ov15_02136670(data_027e10a4);
    if (data_027e0d38->mUnk_14 == 1)
        return false;
    // NONMATCH: OverlayId_29 should be in constant pool
    if (gOverlayManager.mLoadedOverlays[OverlayIndex_6] == OverlayId_29 && data_ov29_0217a4ac[0x54] != 0) {
        return false;
    }

    ItemFlag equipId = mForcedItem;
    bool unk2 = !func_ov00_020849f8(data_027e0e60);
    if (mEquippedItem != ItemFlag_None && (unk2 || (u32)mEquippedItem - 9 <= 1) &&
        (data_027e0fc8 == 0 || func_ov00_020bbd80(data_027e0fc8, param1)) && this->HasItem(mEquippedItem)) {
        equipId = mEquippedItem;
    }

    if (equipId != ItemFlag_None) {
        if (mEquipLoadTimer != 0)
            return param1 == 0;
        return this->GetEquipItem(equipId)->IsUsable(param1);
    }
    return false;
#endif
}

THUMB ShipType ItemManager::GetEquippedShipPart(ShipPart part) const { return mEquippedShipParts[part]; }

THUMB void ItemManager::EquipShipPart(ShipPart part, ShipType type) { mEquippedShipParts[part] = type; }

THUMB s8 ItemManager::GetShipPartCount(ShipPart part, ShipType type) const { return mShipParts[part][type]; }

THUMB void ItemManager::SetShipPartCount(ShipPart part, ShipType type, s8 count) {
    if (count > 99)
        count = 99;
    mShipParts[part][type] = count;
}

THUMB s8 ItemManager::GetTreasureCount(Treasure treasure) const { return mTreasure[treasure]; }

THUMB void ItemManager::SetTreasureCount(Treasure treasure, s8 count) {
    if (count > 99)
        count = 99;
    mTreasure[treasure] = count;
}

THUMB u8 ItemManager::GetUnk_098(u32 index) const { return mUnk_098[index]; }

THUMB u16 ItemManager::GetUnk_09e(u32 index) const { return mUnk_09e[index]; }

THUMB s32 ItemManager::GetUnk_09e_Divided(u32 index) const {
    q20 quotient = Divide(INT_TO_Q20(mUnk_09e[index]), FLOAT_TO_Q20(2.54));
    s32 result = ROUND_Q20(quotient);
    if (result < 1)
        result = 1;
    return result;
}

THUMB void ItemManager::SetUnk_09e(u32 index, u16 value) {
    u8 count = mUnk_098[index] + 1;
    if (count > 99)
        count = 99;
    mUnk_098[index] = count;
    if (value > mUnk_09e[index]) {
        if (value > 9999)
            value = 9999;
        mUnk_09e[index] = value;
    }
}

const u16 sQuiverSizes[] = {20, 20, 30, 50};
const u16 sBombBagSizes[] = {10, 20, 30};

THUMB u16 ItemManager::GetMaxAmmo(ItemFlag equipId) const {
    switch (equipId) {
        case ItemFlag_Bow:
            return (sQuiverSizes + 1)[mQuiverSize];
        case ItemFlag_BombBag:
            return sBombBagSizes[mBombBagSize];
        case ItemFlag_BombchuBag:
            return sBombBagSizes[mBombchuBagSize];
        default:
            return 1;
    }
}

THUMB u8 ItemManager::GetMaxShipPartCount() const { return 99; }

THUMB u8 ItemManager::GetMaxTreasureCount() const { return 99; }

ARM u32 ItemManager::GetActiveFairyLevel(FairyId id) const {
    if (mEquippedFairy == FairyId_None)
        return 0;
    FairyId fairy = this->GetEquippedFairy();
    if (fairy == FairyId_Courage && mUnk_14d != 0)
        return 0;
    fairy = this->GetEquippedFairy();
    if (id == fairy)
        return this->GetFairyLevel(id);
    return 0;
}

ARM u32 ItemManager::GetFairyLevel(FairyId id) const {
    if (this->HasItem(ItemFlag_FAIRY_LV2 + id))
        return 2;
    if (this->HasItem(ItemFlag_FAIRY_LV1 + id))
        return 1;
    return 0;
}

ARM bool ItemManager::HasItem(ItemFlag item) const { return GET_FLAG(mItemFlags.flags, item); }

THUMB void ItemManager::AddItem(ItemFlag item) { SET_FLAG(mItemFlags.flags, item); }

ARM bool ItemManager::IsTreasureSalvaged(u32 index) const { return GET_FLAG(&mSalvagedTreasureFlags, index); }

THUMB void ItemManager::SetTreasureSalvaged(u32 index) { SET_FLAG(&mSalvagedTreasureFlags, index); }

THUMB void ItemManager::RemoveItem(ItemFlag item) {
    RESET_FLAG(mItemFlags.flags, item);
    if (item >= ItemFlag_EQUIP_START && item <= ItemFlag_EQUIP_END) {
        (*mAmmo)[item] = 0;
    }
}
