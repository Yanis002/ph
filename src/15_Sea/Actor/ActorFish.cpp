#include "Actor/ActorFish.hpp"
#include "Actor/ActorManager.hpp"
#include "DTCM/UnkStruct_027e0d38.hpp"
#include "Item/ItemManager.hpp"
#include "Map/MapManager.hpp"
#include "Player/PlayerBase.hpp"
#include "Save/AdventureFlags.hpp"
#include "System/Random.hpp"

struct UnkStruct1 {
    /* 00 */ unk32 mUnk_00;
    /* 04 */ unk32 mUnk_04;
    /* 08 */ unk8 mUnk_08;
    /* 09 */ unk8 mUnk_09;
    /* 0a */ unk8 mUnk_0a;
    /* 0b */ unk8 mUnk_0b;
    /* 0c */ unk32 mUnk_0c;
    /* 10 */ unk32 mUnk_10;
    /* 14 */ unk8 mUnk_14;
    /* 15 */ unk8 mUnk_15;
    /* 16 */ unk16 mUnk_16;
    /* 18 */ unk32 mUnk_18;
    /* 1c */ unk32 mUnk_1c;
    /* 20 */
};
extern u32 **data_027e0fe0[];
extern unk32 data_02063e4c;
extern void *data_027e0d3c;
extern "C" {
void func_01ffbe34(UnkStruct1 *param1);
u32 func_020313c8(unk32 *param1, unk32 param2, unk32 param3, u32 param4, UnkStruct1 *param5);
bool func_ov000_02079470(void *param1, Vec3p *param2, unk32 param3, unk32 param4, unk32 *param5, unk32 *param6, unk32 param7,
                         unk32 param8);
unk32 func_ov003_020f3cd0(u8);
}

char *gShipParts[8]        = {"anc", "bow", "hul", "can", "dco", "pdl", "fnl", "brg"};
ActorType ActorFish::gType = ActorType(ActorTypeId_Fish, (ActorCreateFunc) ActorFish::Create, NULL);

ARM ActorFish *ActorFish::Create() {
    ActorFish *newFish = new(*data_027e0fe0[0], 4) ActorFish();
    return newFish;
}

ARM bool ActorFish::func_ov015_02183bc4(void) {
    Vec3p local_14;
    Vec3p local_20;

    if (this->mUnk_178 == 0x1) {
        local_14 = this->mPos;
        local_20 = gPlayerPos;
        Vec3p_Sub(&local_14, &local_20, &local_14);

        if (Vec3p_Length(&local_14) < 0xC000) {
            return true;
        }
    }

    return false;
}

ARM ActorFish::ActorFish() {}

ARM ActorFish::~ActorFish() {}

struct UnkStruct_027e0ff0_00 {
    /* 00 */ Vec3p *mUnk_00; // offset in the RLAB section (paths)
    /* 04 */ unk32 *mUnk_04; // ?
    /* 08 */
};

struct UnkStruct_027e0ff0 {
    /* 00 */ UnkStruct_027e0ff0_00 *mUnk_00;
    /* 08 */
};
extern UnkStruct_027e0ff0 *data_027e0ff0;

struct UnkStruct_027e1060_00 {
    unk32 mUnk_00;
    unk32 mUnk_04;
    unk32 mUnk_08;
    unk32 mUnk_0C;
    unk32 mUnk_10;
    unk32 mUnk_14;
    unk32 mUnk_18;
    unk32 mUnk_1C;
    unk32 mUnk_20;
    unk32 mUnk_24;
    unk32 mUnk_28;
    unk32 mUnk_2C;
    u16 mUnk_30;
    u16 mUnk_32;
    unk32 mUnk_34;
    unk32 mUnk_38;
    unk32 mUnk_3C;
    unk32 mUnk_40;
    unk32 mUnk_44;
    unk32 mUnk_48;
    unk32 mUnk_4C;
};
struct UnkStruct_027e1060_04 {};

struct UnkStruct_027e1060 {
    /* 00 */ UnkStruct_027e1060_00 *mUnk_00;
    /* 04 */ UnkStruct_027e1060_04 *mUnk_04;
    /* 08 */ unk32 mUnk_08;
    /* 0C */ unk32 mUnk_0C;
    /* 10 */
};
extern UnkStruct_027e1060 data_027e1060;

struct UnkStruct_027e1080 {
    /* 00 */ Vec3p mUnk_00;
    // /* 04 */ unk32 mUnk_04;
    // /* 08 */ unk32 mUnk_08;
    /* 0C */ unk32 mUnk_0C;
    /* 10 */ unk32 mUnk_10;
    /* 14 */
};
extern UnkStruct_027e1080 data_027e1080;
extern UnkStruct_027e1080 data_027e1070;

// non-matching
ARM bool ActorFish::func_ov015_02183cb4(void) {
    u8 bVar1;
    u16 uVar2;
    u64 uVar3;
    s64 lVar4;
    bool bVar5;
    UnkStruct_027e1060 *puVar6;
    UnkStruct_027e1080 *puVar7;
    int iVar8;
    Vec3p *uVar9;
    unk32 uVar10;
    u16 uVar11;
    u16 uVar12;

    if (!gItemManager->HasItem(ItemFlag_FishingRod)) {
        return false;
    }

    this->mUnk_17C = this->mUnk_020.mUnk_00[1] & 0x3;
    this->mUnk_170 = this->mUnk_020.mUnk_00[0];

    if (this->mUnk_020.mUnk_00[0] != 0) {
        this->mUnk_170 = 1;
    }

    // puVar6 = PTR_gRandom_overlay_d_15__021840e8;
    bVar1 = this->mUnk_020.mUnk_0c;

    uVar9 = data_027e0ff0->mUnk_00[bVar1].mUnk_00;

    if (uVar9 == NULL) {
        uVar11 = 0;
    } else {
        uVar11 = gRandom->Next(gRandom->mRandomValue);
        // lVar4 = (ulonglong)*(u32 *)PTR_gRandom_overlay_d_15__021840e8 *
        //         (ulonglong)*(u32 *)(PTR_gRandom_overlay_d_15__021840e8 + 0x8);
        // uVar12 = (u32)lVar4;
        // uVar11 = *(int *)(PTR_gRandom_overlay_d_15__021840e8 + 0x14) +
        //          *(int *)(PTR_gRandom_overlay_d_15__021840e8 + 0xc) *
        //          *(u32 *)PTR_gRandom_overlay_d_15__021840e8 +
        //          *(u32 *)(PTR_gRandom_overlay_d_15__021840e8 + 0x8) *
        //          *(int *)(PTR_gRandom_overlay_d_15__021840e8 + 0x4) +
        //          (int)((ulonglong)lVar4 >> 0x20) +
        //          (u32)CARRY4(*(u32 *)(PTR_gRandom_overlay_d_15__021840e8 + 0x10),uVar12);
        // *(u32 *)PTR_gRandom_overlay_d_15__021840e8 =
        //      *(u32 *)(PTR_gRandom_overlay_d_15__021840e8 + 0x10) + uVar12;
        // *(u32 *)(puVar6 + 0x4) = uVar11;
        // if (uVar9 != 0) {
        //     uVar11 = (u32)((ulonglong)uVar9 * (ulonglong)uVar11 >> 0x20);
        // }
    }

    // ?
    // iVar8 = uVar11 * 0x24 + data_027e0ff0->mUnk_00[bVar1].mUnk_04;
    // this->mPos = iVar8;

    bVar5 = false;

    switch (data_027e0d38->mUnk_0c.func_ov000_020a5e9c()) {
        case 0x0:
        case 0x1: break;
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
        case 0x8:
        case 0x9:
        case 0xA: bVar5 = true; break;
        default: break;
    }

    uVar2          = data_027e1060.mUnk_00->mUnk_30;
    this->mUnk_174 = 0x0;

    if ((uVar2 & (1 << (this->mUnk_17C & 0xFF))) == 0) {
        bVar5 = false;
    }

    if (this->mUnk_170 == 1) {
        puVar7 = &data_027e1080;
        puVar6 = &data_027e1060;

        if (gAdventureFlags->Get(AdventureFlag_Unk15C) == 0x0) {
            return false;
        }

        if (bVar5) {
            unk32 uVar9 = this->mUnk_17C;

            if (data_027e1060.mUnk_00->mUnk_32 & (1 << (uVar9 & 0xFF)) != 0x0) {
                return false;
            }

            if (data_027e1060.mUnk_00->mUnk_30 & (1 << (uVar9 & 0xFF)) != 0x0) {
                // ?
                this->mPos.x = data_027e1070.mUnk_00.x + uVar9 * 0x4;
                this->mPos.z = puVar7->mUnk_00.x + this->mUnk_17C * 0x4;
            }

            this->mUnk_178 = 0x1;
            uVar11         = gRandom->Rand_Next();

            // puVar6 = PTR_gRandom_overlay_d_15__021840e8;
            // lVar4 = (ulonglong)*(u32 *)puVar6 * (ulonglong)*(u32 *)(puVar6 + 0x8);
            // uVar9 = (u32)lVar4;
            // uVar11 = *(int *)(puVar6 + 0x14) +
            //          *(int *)(puVar6 + 0xc) * *(u32 *)puVar6 +
            //          *(u32 *)(puVar6 + 0x8) * *(int *)(puVar6 + 0x4) +
            //          (int)((ulonglong)lVar4 >> 0x20) + (u32)CARRY4(*(u32 *)(puVar6 + 0x10),uVar9);
            // *(u32 *)puVar6 = *(u32 *)(puVar6 + 0x10) + uVar9;
            // uVar3 = (ulonglong)DWORD_overlay_d_15__02184104;
            // *(u32 *)(puVar6 + 0x4) = uVar11;
            // *(int *)(this->mUnk_174) = (int)(uVar3 * uVar11 >> 0x20) + 0x2328;
        } else {
            // puVar7 = data_027e1080;
            // puVar6 = data_027e1060;

            data_027e1060.mUnk_00->mUnk_30 = data_027e1060.mUnk_00->mUnk_30 & ~(u16) (1 << (this->mUnk_17C & 0xFF));
            uVar11                         = gRandom->Rand_Next();

            // puVar7 = PTR_gRandom_overlay_d_15__021840e8;
            // *(u16 *)(puVar6 + 0x32) =
            //      *(u16 *)(puVar6 + 0x32) & ~(u16)(0x1 << (this->mUnk_17C & 0xFF));
            // lVar4 = (ulonglong)*(u32 *)puVar7 * (ulonglong)*(u32 *)(puVar7 + 0x8);
            // uVar11 = (u32)lVar4;
            // uVar9 = *(int *)(puVar7 + 0x14) +
            //         *(int *)(puVar7 + 0xc) * *(u32 *)puVar7 +
            //         *(u32 *)(puVar7 + 0x8) * *(int *)(puVar7 + 0x4) +
            //         (int)((ulonglong)lVar4 >> 0x20) + (u32)CARRY4(*(u32 *)(puVar7 + 0x10),uVar11);
            // *(u32 *)puVar7 = *(u32 *)(puVar7 + 0x10) + uVar11;
            // *(u32 *)(puVar7 + 0x4) = uVar9;

            if (0x14 < (u32) ((u64) uVar9 * 0x64 >> 0x20)) {
                *(u16 *) (puVar6 + 0x32) = *(u16 *) (puVar6 + 0x32) | (u16) (0x1 << (this->mUnk_17C & 0xFF));
                return false;
            }

            this->mUnk_178 = 0x0;
            u64 uVar9      = gRandom->Rand_Next();
            // lVar4 = (ulonglong)*(u32 *)puVar7 * (ulonglong)*(u32 *)(puVar7 + 0x8);
            // uVar11 = (u32)lVar4;
            // uVar9 = *(int *)(puVar7 + 0x14) +
            //         *(int *)(puVar7 + 0xc) * *(u32 *)puVar7 +
            //         *(u32 *)(puVar7 + 0x8) * *(int *)(puVar7 + 0x4) +
            //         (int)((ulonglong)lVar4 >> 0x20) + (u32)CARRY4(*(u32 *)(puVar7 + 0x10),uVar11);
            // uVar3 = (ulonglong)DWORD_overlay_d_15__021840f8;
            // *(u32 *)puVar7 = *(u32 *)(puVar7 + 0x10) + uVar11;
            // *(u32 *)(puVar7 + 0x4) = uVar9;
            *(int *) (this->mUnk_174) = (int) (uVar3 * uVar9 >> 0x20) + 0x12c;
        }
    } else if (bVar5) {
        u32 uVar9 = this->mUnk_17C;

        if (((u32) * (u16 *) (data_027e1060.mUnk_00->mUnk_32) & 0x1 << (uVar9 & 0xFF)) == 0x0) {
            if (((u32) * (u16 *) (data_027e1060.mUnk_00->mUnk_30) & 0x1 << (uVar9 & 0xFF)) != 0x0) {
                this->mPos.x = data_027e1070.mUnk_00.x + uVar9 * 0x4;
                this->mPos.z = puVar7->mUnk_00.x + this->mUnk_17C * 0x4;
            }

            this->mUnk_178 = 0x1;
        } else {
            *(u16 *) (data_027e1060.mUnk_00->mUnk_30) =
                *(u16 *) (data_027e1060.mUnk_00->mUnk_30) & ~(u16) (0x1 << (uVar9 & 0xFF));
            *(u16 *) (puVar6 + 0x32) = *(u16 *) (puVar6 + 0x32) & ~(u16) (0x1 << (this->mUnk_17C & 0xFF));
            // puVar6 = PTR_gRandom_overlay_d_15__021840e8;
            this->mUnk_178 = 0x0;
            // lVar4 = (ulonglong)*(u32 *)puVar6 * (ulonglong)*(u32 *)(puVar6 + 0x8);
            // uVar9 = (u32)lVar4;
            uVar11 = gRandom->Rand_Next();
            // uVar11 = *(int *)(puVar6 + 0x14) +
            //          *(int *)(puVar6 + 0xc) * *(u32 *)puVar6 +
            //          *(u32 *)(puVar6 + 0x8) * *(int *)(puVar6 + 0x4) +
            //          (int)((ulonglong)lVar4 >> 0x20) + (u32)CARRY4(*(u32 *)(puVar6 + 0x10),uVar9);
            // *(u32 *)puVar6 = *(u32 *)(puVar6 + 0x10) + uVar9;
            // *(u32 *)(puVar6 + 0x4) = uVar11;
            // *(int *)(this->mUnk_174) = (int)((ulonglong)uVar11 * 0x2ef >> 0x20) + 0x96;
        }
    } else {
        *(u16 *) (data_027e1060.mUnk_00->mUnk_30) =
            *(u16 *) (data_027e1060.mUnk_00->mUnk_30) & ~(u16) (0x1 << (this->mUnk_17C & 0xFF));
        *(u16 *) (puVar6 + 0x32) = *(u16 *) (puVar6 + 0x32) & ~(u16) (0x1 << (this->mUnk_17C & 0xFF));
        this->mUnk_178           = 0x1;
    }

    this->Actor::vfunc_08();
    this->mUnk_158.func_ov000_020c66e4(&this->mPos, this->mAngle, this->mUnk_020.mUnk_0c, 0);

    return true;
}

ARM void ActorFish::func_ov015_02184108(void) {}

ARM void ActorFish::func_ov015_0218427c(u16 *param1) {
    unk32 iStack_2c;
    unk32 iStack_30;
    UnkStruct1 aStack_28;
    unk32 iVar4;

    if (this->mUnk_178 == 1 && (*param1 & 0x4 || *param1 & 0x8) &&
        func_ov000_02079470(data_027e0d3c, &this->mPos, 0, 0, &iStack_2c, &iStack_30, 0, 0))
    {
        func_01ffbe34(&aStack_28);
        aStack_28.mUnk_04 = 1;

        iVar4 = 0x44;

        if (this->mUnk_170 == 1) {
            iVar4 = 0x45;
        }

        func_020313c8(&data_02063e4c, iStack_2c, iStack_30, iVar4, &aStack_28);
    }
}

class UnkStruct_02184330 {
public:
    unk32 mUnk_00;
    unk32 mUnk_04;
    unk32 mUnk_08;
    unk32 mUnk_0C;
    unk32 mUnk_10;
    unk32 mUnk_14;
    unk32 mUnk_18;
    unk8 mUnk_1C[0x134];
    unk32 mUnk_150;
    unk32 mUnk_154;
    unk32 mUnk_158;
    unk32 mUnk_15C;

    void func_ov015_02184330(s32 param1, unk32 param2, unk32 param3, unk32 param4);
};

inline s32 Test_1(s32 max, s32 min) {
    u64 result = 0;
    s32 value  = (max - min) + 1;

    if (value > 0) {
        result = gRandom->Next3_1(value) >> 32;
    }

    return result + max;
}

// non-matching
ARM void UnkStruct_02184330::func_ov015_02184330(s32 param1, unk32 param2, unk32 param3, unk32 param4) {
    u32 uVar3;
    s32 uVar5;

    // uVar5 = (param2 - param1) + 1;
    this->mUnk_00 = 0;
    this->mUnk_04 = 0;

    // if (uVar5 > 0) {
        // uVar3 = (gRandom->mFactor * (gRandom->mRandomValue >> 32) + gRandom->mAddend);
        // gRandom->mRandomValue = uVar3;

        // if (uVar5) {
        //     uVar3 = (uVar3 * uVar5) >> 32;
        // }

    // }
    // uVar3 = gRandom->Next2((param2 - param1) + 1);
    uVar3 = gRandom->Next3(gRandom->Next_3_2(param2, param1));

    this->mUnk_08 = uVar3;
    this->mUnk_0C = param1;
    this->mUnk_10 = param2;
    this->mUnk_14 = param3;
    this->mUnk_18 = param4;
}

ARM void ActorFish::func_ov015_021843c0(void) {}

ARM bool ActorManager::func_ov015_0218450c(u8 *param1) {
    if (this->mUnk_54.unk_1 == *param1) {
        return false;
    }

    if (this->mUnk_54.unk_2 == *param1) {
        return true;
    }

    if (this->mUnk_54.unk_1 != 0xFF) {
        return true;
    }

    return false;
}

ARM void ActorManager::func_ov015_02184540(void) {
    if (data_027e0d38->mUnk_0c.func_ov000_020a5e9c() == 0) {
        ActorManager_UnkStruct_54 *unk_54 = &this->mUnk_54;

        if (this->mUnk_54.unk_0 == gMapManager->func_ov00_02082d08()) {
            if (func_ov003_020f3cd0(this->mUnk_54.unk_1) == 0 || func_ov003_020f3cd0(this->mUnk_54.unk_2) == 0) {
                this->mUnk_54.unk_1 = this->mUnk_54.unk_2 = 0xFF;
                this->mUnk_3c = this->mUnk_48 = ~0x80000000;
            }
        } else {
            this->mUnk_54.unk_1 = this->mUnk_54.unk_2 = 0xFF;
            this->mUnk_3c = this->mUnk_48 = ~0x80000000;
            this->mUnk_54.unk_0           = gMapManager->func_ov00_02082d08();
        }
    }
}

ARM void ActorManager::func_ov015_021845e8(void) {
    unk8 uVar2;

    if (data_027e0d38->mUnk_0c.func_ov000_020a5e9c() == 0) {
        uVar2 = gMapManager->func_ov00_02082d08();

        if (uVar2 != this->mUnk_64[0]) {
            this->mUnk_64[0] = uVar2;
            this->mUnk_58    = ~0x80000000;
            this->mUnk_5c    = 0;
            this->mUnk_60    = 0;
        }
    }
}

// non-matching (regalloc)
ARM void ActorManager::func_ov015_02184644(void) {
    int iVar1;
    s8 uVar2;
    s32 i;

    if (data_027e0d38->mUnk_0c.func_ov000_020a5e9c() == 0) {
        uVar2 = gMapManager->func_ov00_02082d08();

        if (uVar2 != this->mUnk_bc[7].unk_0_u8) {
            this->mUnk_bc[7].unk_0_s8 = 0;

            for (i = 0; i < ARRAY_LEN(this->mUnk_68); i++) {
                this->mUnk_68[i].unk_0    = ~0x80000000;
                this->mUnk_68[i].unk_4    = 0;
                this->mUnk_68[i].unk_8    = 0;
                this->mUnk_bc[i].unk_0_s8 = 0xFF;
            }

            for (i = 0; i < ARRAY_LEN(this->mUnk_a4); i++) {
                this->mUnk_a4[i].unk_0        = ~0x80000000;
                this->mUnk_a4[i].unk_4        = 0;
                this->mUnk_a4[i].unk_8        = 0;
                this->mUnk_bc[i + 5].unk_0_u8 = 0xFF;
            }
        }
    }
}

ARM void ActorManager::func_ov015_021846f8(ActorManager_UnkStruct_68 *param1, unk32 *pIndex) {
    ActorManager_UnkStruct_68 *entry = &this->mUnk_68[*pIndex];

    entry->unk_0 = param1->unk_0;
    entry->unk_4 = param1->unk_4;
    entry->unk_8 = param1->unk_8;
}

ARM void ActorManager::func_ov015_02184728(unk8 *param1, unk32 *param2) {
    this->mUnk_bc[*param2].unk_0_s8 = *param1;
}

// non-matching
ARM void ActorManager::func_ov015_0218473c(ActorManager_UnkStruct_68 *param1, u16 *param2) {
    u16 uVar1;
    int iVar2;
    int iVar3;

    iVar3 = 0x0;
    do {

        uVar1 = (u8) this->mUnk_bc[iVar3 + 5].unk_0_u8;

        if (*param2 == uVar1) {
            this->mUnk_a4[iVar3].unk_0 = param1->unk_0;
            this->mUnk_a4[iVar3].unk_4 = param1->unk_4;
            this->mUnk_a4[iVar3].unk_8 = param1->unk_8;
            return;
        }

        iVar3++;
        // if (uVar1 == 0xFF) {
        //     break;
        // }

        // if (1 < iVar3) {
        //     return;
        // }
    } while (uVar1 != 0xFF);

    // iVar2 = iVar3 * 0xc + param_1;
    // *(char *)(param_1 + iVar3 + 0xc1) = (char)*param2;
    // *(undefined4 *)(iVar2 + 0xa4) = param1[0x0];
    // *(undefined4 *)(iVar2 + 0xa8) = param1[0x1];
    // *(undefined4 *)(iVar2 + 0xac) = param1[0x2];
    this->mUnk_bc[iVar3 + 5].unk_0_u8 = *param2;
    this->mUnk_a4[iVar3].unk_0        = param1->unk_0;
    this->mUnk_a4[iVar3].unk_4        = param1->unk_4;
    this->mUnk_a4[iVar3].unk_8        = param1->unk_8;
}

// non-matching
ARM void ActorManager::func_ov015_021847bc(ActorManager_UnkStruct_68 *param1, ActorManager *actorManager, u16 *param3) {
    int iVar2;

    iVar2 = 0x0;

    do {
        if (*param3 == actorManager->mUnk_bc[iVar2 + 5].unk_0_u8) {
            param1->unk_0 = actorManager->mUnk_a4[iVar2].unk_0;
            param1->unk_4 = actorManager->mUnk_a4[iVar2].unk_4;
            param1->unk_8 = actorManager->mUnk_a4[iVar2].unk_8;
            return;
        }
        iVar2++;
    } while (iVar2 < 2);

    param1->unk_0 = ~0x80000000;
    param1->unk_4 = 0x0;
    param1->unk_8 = 0x0;
}

ARM void ActorManager::func_ov015_02184838(void) {
    s32 i;
    Actor **ppActor;

    ppActor = this->mActorTable;

    for (i = 0; i < this->mMaxActorIndex; i++) {
        ActorFish2 *pActor = (ActorFish2 *) *ppActor;

        if (pActor != NULL && pActor->mAlive) {
            if (pActor->mType == ActorTypeId_TSIP) {
                pActor->mUnk_29e = 0;
            } else if (pActor->mType == ActorTypeId_DNPC) {
                pActor->mUnk_39a = 0;
            } else if (pActor->mType == ActorTypeId_GOC2) {
                pActor->mUnk_4a9 = 0;
            } else if (pActor->mType == ActorTypeId_BUII) {
                pActor->mUnk_2f2 = 1;
            }
        }

        ppActor++;
    }
}

ARM void ActorManager::func_ov015_021848dc(void) {
    s32 i;
    Actor **ppActor;

    ppActor = this->mActorTable;

    for (i = 0; i < this->mMaxActorIndex; i++) {
        ActorFish2 *pActor = (ActorFish2 *) *ppActor;

        if (pActor != NULL && pActor->mAlive) {
            if (pActor->mType == ActorTypeId_TSIP) {
                pActor->mUnk_29f = 0;
            } else if (pActor->mType == ActorTypeId_DNPC) {
                pActor->mUnk_39b = 0;
            } else if (pActor->mType == ActorTypeId_GOC2) {
                pActor->mUnk_4aa = 0;
            }
        }

        ppActor++;
    }
}
