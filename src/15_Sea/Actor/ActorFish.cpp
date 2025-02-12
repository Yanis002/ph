#include "Actor/ActorFish.hpp"
#include "Actor/ActorManager.hpp"
#include "DTCM/UnkStruct_027e0d38.hpp"
#include "Item/ItemManager.hpp"
#include "Map/MapManager.hpp"
#include "Player/PlayerBase.hpp"
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

ARM void ActorFish::func_ov015_02183cb4(void) {}
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

// non-matching
ARM void ActorManager::func_ov015_02184330(unk32 param1, Actor *param2, unk32 param3, unk32 param4) {
    s64 lVar1;
    unk8 *puVar2;
    u32 uVar3;
    u32 uVar4;
    s32 uVar5;

    uVar3 = 0;
    // this->mUnk_158 = 0;
    // uVar5 = (param2 - param1) + 1;
    // this->mUnk_15C = 0;
    // puVar2 = gRandom;

    if (uVar5 > 0) {
        // lVar1 = (u64)*(u32 *)gRandom * (u64)*(u32 *)(gRandom->mFactor);
        // uVar4 = (u32)lVar1;

        uVar3 = gRandom->Next(gRandom->mRandomValue);

        // uVar3 = *(int *)(gRandom->mAddend) + *(int *)(gRandom->mFactor) * *(u32 *)gRandom->mRandomValue +
        //         *(u32 *)(gRandom->mFactor) *
        //         *(int *)(gRandom->mRandomValue) + (int)((u64)lVar1 >> 0x20)
        //         + (u32)CARRY4(*(u32 *)(gRandom->mAddend),uVar4);

        // *(u32 *)gRandom = *(u32 *)(gRandom->mAddend) + uVar4;
        // *(u32 *)(puVar2 + 0x4) = uVar3;

        // if (uVar5 != 0) {
        //     uVar3 = (u32)((u64)uVar5 * (u64)uVar3 >> 32);
        // }
    }

    this->mCacheEmptyActorIndex = param1 + uVar3;
    this->mNextActorId          = param1;
    this->mActorTable[0]        = param2;
    this->mUnk_14               = &param3;
    this->mUnk_18[0]            = param4;
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
    unk8 uVar2;

    if (data_027e0d38->mUnk_0c.func_ov000_020a5e9c() == 0) {
        uVar2 = gMapManager->func_ov00_02082d08();

        if (uVar2 != (u8) this->mUnk_bc[7].unk_0) {
            this->mUnk_bc[7].unk_0 = 0;

            for (s32 i = 0; i < ARRAY_LEN(this->mUnk_68); i++) {
                this->mUnk_68[i].unk_0 = ~0x80000000;
                this->mUnk_68[i].unk_4 = 0;
                this->mUnk_68[i].unk_8 = 0;
                this->mUnk_bc[i].unk_0 = 0xFF;
            }

            for (s32 i = 0; i < ARRAY_LEN(this->mUnk_a4); i++) {
                this->mUnk_a4[i].unk_0     = ~0x80000000;
                this->mUnk_a4[i].unk_4     = 0;
                this->mUnk_a4[i].unk_8     = 0xFF;
                this->mUnk_bc[i + 5].unk_0 = 0;
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
    this->mUnk_bc[*param2].unk_0 = *param1;
}

// non-matching
ARM void ActorManager::func_ov015_0218473c(unk32 *param1, u16 *param2) {
    u16 uVar1;
    int iVar2;
    int iVar3;

    iVar3 = 0x0;
    do {

        uVar1 = (u8) this->mUnk_bc[iVar3 + 5].unk_0;

        if (*param2 == uVar1) {
            this->mUnk_a4[iVar3].unk_0 = param1[0x0];
            this->mUnk_a4[iVar3].unk_4 = param1[0x1];
            this->mUnk_a4[iVar3].unk_8 = param1[0x2];
            return;
        }

        // if (uVar1 == 0xff) {
        //     break;
        // }

        iVar3++;
        // if (1 < iVar3) {
        //     return;
        // }
    } while (uVar1 != 0xff);

    // iVar2 = iVar3 * 0xc + param_1;
    // *(char *)(param_1 + iVar3 + 0xc1) = (char)*param2;
    // *(undefined4 *)(iVar2 + 0xa4) = param1[0x0];
    // *(undefined4 *)(iVar2 + 0xa8) = param1[0x1];
    // *(undefined4 *)(iVar2 + 0xac) = param1[0x2];
    this->mUnk_bc[iVar3 + 5].unk_0 = *param2;
    this->mUnk_a4[iVar3].unk_0     = param1[0x0];
    this->mUnk_a4[iVar3].unk_4     = param1[0x1];
    this->mUnk_a4[iVar3].unk_8     = param1[0x2];
}

// non-matching
ARM void ActorManager::func_ov015_021847bc(ActorManager_UnkStruct_68 *param1, ActorManager *actorManager, u16 *param3) {
    int iVar2;

    iVar2 = 0x0;

    do {
        if (*param3 == actorManager->mUnk_bc[iVar2 + 5].unk_0) {
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

// non-matching
ARM void ActorManager::func_ov015_02184838(void) {
    for (s32 i = 0; i < this->mMaxActorIndex; i++) {
        ActorFish2 *pActor = (ActorFish2 *) this->mActorTable[i];

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
    }
}

// non-matching
ARM void ActorManager::func_ov015_021848dc(void) {
    for (s32 i = 0; i < this->mMaxActorIndex; i++) {
        ActorFish2 *pActor = (ActorFish2 *) this->mActorTable[i];

        if (pActor != NULL && pActor->mAlive) {
            if (pActor->mType == ActorTypeId_TSIP) {
                pActor->mUnk_29f = 0;
            } else if (pActor->mType == ActorTypeId_DNPC) {
                pActor->mUnk_39b = 0;
            } else if (pActor->mType == ActorTypeId_GOC2) {
                pActor->mUnk_4aa = 0;
            }
        }
    }
}
