#pragma once

#include "types.h"

#include "Item/Item.hpp"

typedef u32 OverlayId;
enum OverlayId_ {
    OverlayId_Core,
    OverlayId_01,
    OverlayId_02,
    OverlayId_03,
    OverlayId_Memory,
    OverlayId_05,
    OverlayId_06,
    OverlayId_07,
    OverlayId_08,
    OverlayId_09,
    OverlayId_10,
    OverlayId_11,
    OverlayId_12,
    OverlayId_13,
    OverlayId_Land,
    OverlayId_15,
    OverlayId_16,
    OverlayId_17,
    OverlayId_18,
    OverlayId_19,
    OverlayId_20,
    OverlayId_21,
    OverlayId_22,
    OverlayId_23,
    OverlayId_24,
    OverlayId_25,
    OverlayId_26,
    OverlayId_27,
    OverlayId_28,
    OverlayId_29,
    OverlayId_30,
    OverlayId_31,
    OverlayId_32,
    OverlayId_33,
    OverlayId_34,
    OverlayId_35,
    OverlayId_36,
    OverlayId_37,
    OverlayId_38,
    OverlayId_39,
    OverlayId_40,
    OverlayId_41,
    OverlayId_42,
    OverlayId_43,
    OverlayId_44,
    OverlayId_45,
    OverlayId_46,
    OverlayId_47,
    OverlayId_48,
    OverlayId_49,
    OverlayId_50,
    OverlayId_51,
    OverlayId_52,
    OverlayId_PlayerBoomerang,
    OverlayId_PlayerScoop,
    OverlayId_PlayerBomb,
    OverlayId_PlayerBow,
    OverlayId_PlayerRope,
    OverlayId_PlayerBombchu,
    OverlayId_PlayerHammer,
    OverlayId_60,
    OverlayId_61,
};

typedef u32 OverlayIndex;
enum OverlayIndex_ {
    OverlayIndex_Core,
    OverlayIndex_1,
    OverlayIndex_2,
    OverlayIndex_3,
    OverlayIndex_4,
    OverlayIndex_5,
    OverlayIndex_6,
    OverlayIndex_7,
    OverlayIndex_8,
    OverlayIndex_9,
    OverlayIndex_10,
    OverlayIndex_EquipItem,
    OverlayIndex_12,
    OverlayIndex_COUNT,
};

class OverlayManager {
  public:
    OverlayId mLoadedOverlays[OverlayIndex_COUNT];

    void Unload(OverlayIndex index);
    void Load(OverlayIndex index, OverlayId id);
    void LoadIfNotLoaded(OverlayIndex index, OverlayId id);
    void LoadEquipItem(ItemFlag equipId);
};

extern OverlayManager gOverlayManager;
