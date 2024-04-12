#pragma once

#include "global.h"
#include "lib/math.h"
#include "types.h"

#include "Actor/ActorNavi.hpp"
#include "Item/Item.hpp"
#include "Player/EquipItem.hpp"
#include "Render/ModelRender.hpp"
#include "System/OverlayManager.hpp"
#include "System/SysNew.hpp"

#define MAX_HOURGLASS_SECONDS 1500 // 25 minutes

typedef s32 FairyId;
enum FairyId_ {
    FairyId_None = -1,
    FairyId_Courage = 0,
    FairyId_Power = 1,
    FairyId_Wisdom = 2,
    FairyId_COUNT = 3,
};

enum Gem {
    Gem_Courage,
    Gem_Power,
    Gem_Wisdom,
    Gem_COUNT,
};

typedef u32 ShipPart;
enum ShipPart_ {
    ShipPart_Anchor,
    ShipPart_Prow,
    ShipPart_Hull,
    ShipPart_Cannon,
    ShipPart_Handrail,
    ShipPart_Wheel,
    ShipPart_Chimney,
    ShipPart_Bridge,
    ShipPart_COUNT,
};

typedef u32 ShipType;
enum ShipType_ {
    ShipType_Linebeck,
    ShipType_Bright,
    ShipType_Iron,
    ShipType_Stone,
    ShipType_Vintage,
    ShipType_Demon,
    ShipType_Tropical,
    ShipType_Dignified,
    ShipType_Golden,
    ShipType_COUNT,
};

typedef u32 ShipItem;
#define SHIP_ITEM(part, ship) (ShipPart_##part * ShipPart_COUNT + ShipType_##type)
#define ShipItem_COUNT (ShipPart_COUNT * ShipType_COUNT)

typedef u32 Treasure;
enum Treasure_ {
    Treasure_PinkCoral,
    Treasure_WhitePearlLoop,
    Treasure_DarkPearlLoop,
    Treasure_ZoraScale,
    Treasure_GoronAmber,
    Treasure_RutoCrown,
    Treasure_HelmarocPlume,
    Treasure_RegalRing,

    Treasure_COUNT,
};

#define NUM_POTIONS 2
typedef u8 Potion;
enum Potion_ {
    Potion_None,
    Potion_Red,
    Potion_Blue,
    Potion_Yellow,
    Potion_COUNT,
};

struct ItemFlags {
    /* 00 */ u32 flags[CEIL_DIV(ItemFlag_COUNT, 32)];
    /* 10 */
};

struct ShipPartPricesShown {
    /* 0 */ u32 flags[CEIL_DIV(ShipItem_COUNT, 32)];
    /* c */
};

struct UnkStruct_027e0d38 {
    /* 00 */ unk8 mUnk_00;
    /* 01 */ unk8 mUnk_01[3]; // padding?
    /* 04 */ unk32 mUnk_04;
    /* 08 */ unk32 mUnk_08;
    /* 0c */ unk32 mUnk_0c;
    /* 10 */ unk32 mUnk_10;
    /* 14 */ unk32 mUnk_14;
    /* 18 */ unk32 mUnk_18;
    /* 1c */ unk16 mUnk_1c;
    /* 1e */ unk8 mUnk_1e;
    /* 1f */ unk8 mUnk_1f;
    /* 20 */ unk8 mUnk_20;
    /* 21 */ unk8 mUnk_21;
    /* 22 */ unk8 mUnk_22[2]; // padding?
    /* 24 */ void* mUnk_24;
    /* 28 */ void* mUnk_28;
    /* 2c */
};

typedef u32 ItemModelId;
enum ItemModelId_ {
    ItemModelId_OshusSword, // swA
    ItemModelId_PhantomSword, // swB
    ItemModelId_WoodenShield, // shA
    ItemModelId_Bow, // bow
    ItemModelId_Arrow, // arrow
    ItemModelId_ArrowS, // arrow_s, purpose unknown
    ItemModelId_Boomerang, // boomerang
    ItemModelId_Scoop, // scp
    ItemModelId_Bomb, // bomb
    ItemModelId_Bombchu, // bomchu
    ItemModelId_RedPotion, // rev_bin
    ItemModelId_PurplePotion, // rev_binP
    ItemModelId_YellowPotion, // rev_binY
    ItemModelId_Hammer, // ham
    ItemModelId_RopeTop, // ropetop
    ItemModelId_BombchuPt, // bomchu_pt, purpose unknown
    ItemModelId_COUNT,
};
typedef u32 DungeonItemModelId;
enum DungeonItemModelId_ {
    DungeonItemModelId_ForceGem, // force
    DungeonItemModelId_BossKey, // bosskey
    DungeonItemModelId_RoundCrystal, // switch_cstl_c_c
    DungeonItemModelId_SquareCrystal, // switch_cstl_s_c
    DungeonItemModelId_TriangleCrystal, // switch_cstl_t_c
    DungeonItemModelId_COUNT,
};

struct SaveItemManager {
    /* 00 */ ItemFlags itemFlags;
    /* 10 */ u32 salvagedTreasureFlags;
    /* 14 */ ShipPartPricesShown shipPartPricesShown;
    /* 20 */ u32 treasurePriceShownFlags[CEIL_DIV(Treasure_COUNT, 32)];
    /* 24 */ u8 equippedShipParts[ShipPart_COUNT];
    /* 2c */ s8 shipParts[ShipPart_COUNT][ShipType_COUNT];
    /* 74 */ s8 treasure[Treasure_COUNT];
    /* 7c */ unk8 unk_7c[4];
    /* 80 */ u16 hourglassSeconds;
    /* 82 */ u16 unk_82[6];
    /* 8e */ u16 numRupees;
    /* 90 */ unk8 unk_90;
    /* 91 */ unk8 unk_91;
    /* 92 */ unk8 unk_92;
    /* 93 */ u8 numBombs;
    /* 94 */ u8 numBombchus;
    /* 95 */ u8 numArrows;
    /* 96 */ s8 equippedItem;
    /* 97 */ Potion potions[NUM_POTIONS];
    /* 99 */ u8 numGems[Gem_COUNT];
    /* 9c */ u8 quiverSize;
    /* 9d */ u8 bombBagSize;
    /* 9e */ u8 bombchuBagSize;
    /* 9f */ u8 unk_9f[6];
    /* a5 */ u8 equippedFairy;
    /* a6 */
};

class ItemManager : public SysObject {
  private:
    /* 000 */ ItemFlag mEquippedItem;
    /* 004 */ ItemFlag mPrevEquippedItem;
    /* 008 */ ItemFlag mForcedItem; // game crashes when any item besides this one is equipped
    /* 00c */ u32 mHourglassSandFrames;
    /* 010 */ FairyId mEquippedFairy;
    /* 014 */ ActorNavi* mFairies[FairyId_COUNT];
    /* 020 */ u16 mEquipLoadTimer;
    /* 022 */ u16 mNumRupees;
    /* 024 */ u8 mNumGems[Gem_COUNT];
    /* 027 */ unk8 mUnk_027; // padding?
    /* 028 */ ShipType mEquippedShipParts[ShipPart_COUNT];
    /* 048 */ s8 mShipParts[ShipPart_COUNT][ShipType_COUNT];
    /* 090 */ s8 mTreasure[Treasure_COUNT];
    /* 098 */ u8 mUnk_098[6]; // max 99
    /* 09e */ u16 mUnk_09e[6]; // max 9999, corresponds with mUnk_098
    /* 0aa */ unk16 mUnk_0aa; // padding?
    /* 0ac */ EquipItem* (*mEquipItems)[ItemFlag_EQUIP_COUNT];
    /* 0b0 */ u16 (*mAmmo)[ItemFlag_EQUIP_COUNT];
    /* 0b4 */ u16 mQuiverSize;
    /* 0b6 */ u16 mBombBagSize;
    /* 0b8 */ u16 mBombchuBagSize;
    /* 0ba */ unk16 mUnk_0ba; // only between 0 and 9
    /* 0bc */ Potion mPotions[2];
    /* 0be */ unk8 mUnk_0be[2]; // padding?
    /* 0c0 */ ItemModel* mItemModels[ItemModelId_COUNT];
    /* 100 */ ItemModel* mDungeonItemModels[DungeonItemModelId_COUNT]; // non-null in dungeons/caves
    /* 114 */ ModelRender* mUnk_114;
    /* 118 */ ItemId mFanfareItem;
    /* 11c */ unk32 mUnk_11c;
    /* 120 */ void* mFanfareItemModel;
    /* 124 */ void* mUnk_124;
    /* 128 */ ItemFlags mItemFlags;
    /* 138 */ u32 mSalvagedTreasureFlags;
    /* 13c */ ShipPartPricesShown mShipPartPricesShown;
    /* 148 */ u32 mTreasurePriceShownFlags[CEIL_DIV(Treasure_COUNT, 32)];
    /* 14c */ unk8 mUnk_14c;
    /* 14d */ u8 mUnk_14d;
    /* 14e */ unk8 mUnk_14e[0x2];
    /* 150 */

  public:
    static ItemManager* Create();
    static void Destroy();
    ItemManager();
    ~ItemManager();

    // Save/load
    void Save(SaveItemManager* save);
    void Load(const SaveItemManager* save);

    // Fairy
    FairyId GetEquippedFairy() const;
    ActorNavi* GetFairy(FairyId id) const;
    u32 GetActiveFairyLevel(FairyId id) const;
    u32 GetFairyLevel(FairyId id) const;

    // Equip item
    void ClearPrevEquippedItem();
    void TickEquipItem();
    ItemFlag GetEquippedItem() const;
    void Sword_vfunc_38(unk32 param1);
    void Shield_vfunc_38(unk32 param1);
    void EquipItem_vfunc_38(unk32 param1);
    bool EquipItem_vfunc_3c(Vec4p* param1, ItemFlag equipId);
    void EquipItem_vfunc_2c(ItemFlag equipId);
    EquipItem* GetEquipItem(ItemFlag equipId);
    bool func_ov00_020ad790(unk32 param1);
    bool SetEquippedItem(ItemFlag equipId);
    void EquipPreviousItem();
    void ForceEquipItem(ItemFlag equipId);
    bool ClearForcedEquipItem();
    void UpdateSwordShieldInUse();

    // Ammo
    u16 GetAmmo(ItemFlag equipId) const;
    void GiveAmmo(ItemFlag equipId, u16 amount);
    u16 GetMaxAmmo(ItemFlag equipId) const;
    void UpgradeQuiver();
    void UpgradeBombBag();
    void UpgradeBombchuBag();

    // Item model
    void func_ov00_020ad528();
    ItemModel* GetItemModel(ItemModelId id);
    void func_ov00_020ad538(unk32 param1) const;
    void func_ov00_020ad560(unk32 param1) const;
    ItemModel* GetDungeonItemModel(DungeonItemModelId id);
    void func_ov00_020ad594(unk32 param1) const;
    void LoadFanfareItem(ItemId id);
    bool GetFanfareItemScale(Vec3p* pScale) const;
    void LoadDungeonItemModels();

    // Ship
    ShipType GetEquippedShipPart(ShipPart part) const;
    void EquipShipPart(ShipPart part, ShipType type);
    s8 GetShipPartCount(ShipPart part, ShipType type) const;
    void SetShipPartCount(ShipPart part, ShipType type, s8 count);
    bool HasShipPartPriceShown(ShipPart part, ShipType type) const;
    void AddShipPartPriceShown(ShipPart part, ShipType type);
    u8 GetMaxShipPartCount() const;

    // Treasure
    s8 GetTreasureCount(Treasure treasure) const;
    void SetTreasureCount(Treasure treasure, s8 count);
    bool HasTreasurePriceShown(Treasure treasure) const;
    void AddTreasurePriceShown(Treasure treasure);
    bool IsTreasureSalvaged(u32 index) const;
    void SetTreasureSalvaged(u32 index);
    u8 GetMaxTreasureCount() const;

    // mUnk_098, mUnk_09e
    u8 GetUnk_098(u32 index) const;
    u16 GetUnk_09e(u32 index) const;
    s32 GetUnk_09e_Divided(u32 index) const;
    void SetUnk_09e(u32 index, u16 value); // also increments the corresponding mUnk_098 value

    // Item
    bool HasItem(ItemFlag item) const;
    void AddItem(ItemFlag item);
    void RemoveItem(ItemFlag item);
    void GiveItem(ItemId id, unk32 param2, unk32 param3);
    void GiveEquipItem(ItemFlag item, u16 ammo);

    // Rupees
    u32 GetMaxRupees() const;
    void GiveRupees(u16 amount, unk32 param2);

    // Potion
    void SetPotion(u32 index, Potion potion);
    bool HasPotion(u32 index) const;
    bool HasAllPotions() const;
    bool HasPurplePotion() const;
    void UnequipPotion();

    // Unknown
    void func_ov00_020ae350() const;
    void GiveKeys(u32 amount);
    void func_ov00_020ae4dc(unk32 param1); // sets mUnk_0ba
    void func_ov00_020ae648(unk32 param1, unk32 param2, unk32 param3);
};

extern ItemManager* gItemManager;
