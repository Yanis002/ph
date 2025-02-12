#pragma once

#include "global.h"
#include "types.h"

#include "Actor/Actor.hpp"
#include "Actor/ActorRef.hpp"
#include "Actor/FilterActorBase.hpp"
#include "Physics/AABB.hpp"
#include "Physics/Sphere.hpp"

struct ActorManager_UnkStruct_68 {
    /* 0 */ u32 unk_0;
    /* 4 */ u32 unk_4;
    /* 8 */ u32 unk_8;
    /* c */
};

class FilterActor : public FilterActorBase {
    /* 00 (base) */
    /* 04 */ u32 mType;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ ActorRef *mExcludeRefs; // list of excluded actor ids, terminated by -1
    /* 14 */ bool mExcludeNotInAABB;
    /* 15 */ unk8 mUnk_15[3];
    /* 18 */ AABB mAABB;
    /* 30 */ bool mExcludeNotInSphere;
    /* 31 */ unk8 mUnk_1a[3];
    /* 34 */ Sphere mSphere;
    /* 44 */

    /* 0 */ virtual bool Filter(Actor *actor) override;
    /* 4 */
};

struct ActorList {
    /* 0 */ ActorRef *actors;
    /* 4 */ s32 capacity;
    /* 8 */ s32 length;
    /* c */
};

struct ActorManager_UnkStruct_54 {
    /* 00 */ u8 unk_0;
    /* 00 */ u8 unk_1;
    /* 00 */ u8 unk_2;
    /* 00 */ u8 unk_3;
};

struct ActorManager_UnkStruct_bc {
    /* 00 */ unk8 unk_0;
};

class ActorManager {
public:
    /* 00 */ u16 mMaxActors;
    /* 02 */ u16 mNumActors;
    /* 04 */ unk32 mMaxActorIndex;
    /* 08 */ s32 mCacheEmptyActorIndex;
    /* 0c */ unk32 mNextActorId;
    /* 10 */ Actor **mActorTable;
    /* 14 */ void *mUnk_14;
    /* 18 */ unk8 mUnk_18[4];
    /* 1c */ unk32 mUnk_1c;
    /* 20 */ unk32 mUnk_20;
    /* 24 */ unk32 mUnk_24;
    /* 28 */ unk8 mUnk_28;
    /* 29 */ bool mUnk_29;
    /* 2a */ unk8 mUnk_2a;
    /* 2b */ unk8 mUnk_2b;
    /* 2c */ unk32 mUnk_2c;
    /* 30 */ unk32 mUnk_30;
    /* 34 */ unk32 mUnk_34;
    /* 38 */ unk8 mUnk_38[4];
    /* 3c */ u32 mUnk_3c;
    /* 40 */ unk32 mUnk_40;
    /* 44 */ unk32 mUnk_44;
    /* 48 */ u32 mUnk_48;
    /* 4c */ unk32 mUnk_4c;
    /* 50 */ unk32 mUnk_50;
    /* 54 */ ActorManager_UnkStruct_54 mUnk_54;
    /* 58 */ u32 mUnk_58;
    /* 5c */ unk32 mUnk_5c;
    /* 60 */ unk32 mUnk_60;
    /* 64 */ u8 mUnk_64[4];
    /* 68 */ ActorManager_UnkStruct_68 mUnk_68[5];
    /* a4 */ ActorManager_UnkStruct_68 mUnk_a4[2];
    /* bc */ ActorManager_UnkStruct_bc mUnk_bc[8];
    /* c4 */

    void DeleteActor(u32 index, bool param2);
    static void func_ov00_020c3484(ActorRef *ref, ActorManager *actorMgr, unk32 param3);
    void Actor_vfunc_10(u32 param1);
    Actor *FindActorById(s32 id);
    Actor *GetActor(ActorRef *ref);
    s32 FilterActors(FilterActorBase *filter, ActorList *filteredActors);
    static void FindActorByType(ActorRef *ref, ActorManager *actorMgr, ActorTypeId type);
    static void FindNearestActorOfType(ActorRef *ref, ActorManager *actorMgr, ActorTypeId type, Vec3p *pos);
    bool func_ov00_020c398c(u32 index);
    void func_ov00_020c399c(u32 index, Cylinder *cylinder);
    Actor *func_ov00_020c39ac(s32 index, const ActorTypeId *actorTypes, bool param3);
    s32 func_ov00_020c3b2c(s32 *param1);
    s32 func_ov00_020c3bb0(unk32 param1, s32 *param2);
    void func_ov00_020c3ce8(unk32 param1, bool param2);
    void Actor_vfunc_28();
    static bool ActorTypeIsOneOf(ActorTypeId type, const ActorTypeId *types);

    static void Create();
    static void Destroy();
    ActorManager();
    ~ActorManager();
    void func_ov004_0210532c();
    void func_ov004_021053dc();
    void func_ov004_021054a4(s32 *param1, s32 param2, unk32 param3);
    void func_ov004_0210554c();
    bool func_ov004_02105578(unk32 param1);
    bool func_ov004_02105608(unk32 param1, unk32 param2, unk32 param3);
    void func_ov004_021056b8();

    // ActorFish
    void func_ov015_02184330(unk32 param1, Actor* param2, unk32 param3, unk32 param4);
    bool func_ov015_0218450c(u8* param1);
    void func_ov015_02184540(void);
    void func_ov015_021845e8(void);
    void func_ov015_02184644(void);
    void func_ov015_021846f8(ActorManager_UnkStruct_68* param1, unk32* pIndex);
    void func_ov015_02184728(unk8* param1, unk32* param2);
    void func_ov015_0218473c(unk32* param1, u16* param2);
    static void func_ov015_021847bc(ActorManager_UnkStruct_68* param1, ActorManager* actorManager, u16* param3);
    void func_ov015_02184838(void);
    void func_ov015_021848dc(void);
};

extern ActorManager *gActorManager;
