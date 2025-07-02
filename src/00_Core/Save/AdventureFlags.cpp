#include "Save/AdventureFlags.hpp"
#include "Cutscene/CutsceneHandler.hpp"

extern void func_ov000_020980f8(CutsceneHandler *cutsceneHandler);
extern unk32 func_ov000_020980fc(CutsceneHandler *cutsceneHandler);
extern bool func_ov000_02098114(CutsceneHandler *cutsceneHandler);
extern u8 data_ov000_020e310c[];
extern u8 data_ov000_020e313c[];
extern u8 data_ov000_020e3140[];
extern u8 data_ov000_020e3144[];
extern u8 data_ov000_020e314c[];
extern u8 data_ov000_020e314e[];
extern u8 data_ov000_020e3150[];
extern u8 data_ov000_020e3154[];
extern u8 data_ov000_020e3155[];
extern u8 data_ov000_020e3156[];

bool AdventureFlags::Exists() {
    return gAdventureFlags != NULL;
}

void AdventureFlags::CopyTo(unk32 *flags) {}

void AdventureFlags::func_ov00_02097674() {
    func_ov000_020980f8(this->mCutsceneHandler);
}

s32 AdventureFlags::func_ov00_02097684() {
    return func_ov000_020980fc(this->mCutsceneHandler);
}

void AdventureFlags::Load() {}
void AdventureFlags::func_ov00_020976c8() {}
void AdventureFlags::func_ov00_02097700() {}
bool AdventureFlags::func_ov00_02097738() {}
unk8 AdventureFlags::func_ov00_02097750() {}
bool AdventureFlags::Get(AdventureFlag flag) {}
void AdventureFlags::Set(AdventureFlag flag, bool value) {}
void AdventureFlags::func_Ov00_02097810(s32 param1) {}
unk32 AdventureFlags::func_ov00_02097968(unk32 param1) {}
unk32 AdventureFlags::func_ov00_02097a44(unk32 param1, s32 param2) {}
bool AdventureFlags::func_ov00_02097b9c(s32 param1) {}
bool AdventureFlags::func_ov00_02097bac() {}
bool AdventureFlags::func_ov00_02097bbc() {}
bool AdventureFlags::func_ov00_02097bcc() {}
bool AdventureFlags::func_ov00_02097bcc(s32 param2) {}
s32 AdventureFlags::func_ov00_02097c08() {}

bool AdventureFlags::Get_FlagsUnk_30_Flag(s32 index) {
    unk32 unk30 = this->Get_FlagsUnk_30(index);

    return this->Get(unk30);
}

u8 AdventureFlags::Get_FlagsUnk_49(s32 index) {
    return data_ov000_020e3155[index * 0x4C];
}

u8 AdventureFlags::Get_FlagsUnk_48(s32 index) {
    return data_ov000_020e3154[index * 0x4C];
}

u8 AdventureFlags::Get_FlagsUnk_4a(s32 index) {
    return data_ov000_020e3156[index * 0x4C];
}

u16 AdventureFlags::Get_FlagsUnk_42(s32 index) {
    return *(u16 *) (data_ov000_020e314e + index * 0x4C);
}

u16 AdventureFlags::Get_FlagsUnk_40(s32 index) {
    return *(unk16 *) (data_ov000_020e314c + index * 0x4C);
}

unk32 AdventureFlags::Get_FlagsUnk_38(s32 index) {
    return *(unk32 *) (data_ov000_020e3144 + index * 0x4C);
}

unk32 AdventureFlags::Get_FlagsUnk_34(s32 index) {
    return *(unk32 *) (data_ov000_020e3140 + index * 0x4C);
}

unk32 AdventureFlags::Get_FlagsUnk_44(s32 index) {
    return *(unk32 *) (data_ov000_020e3150 + index * 0x4C);
}

unk32 AdventureFlags::Get_FlagsUnk_30(s32 index) {
    return *(unk32 *) (data_ov000_020e313c + index * 0x4C);
}

bool AdventureFlags::Get_FlagsUnk_00(s32 index, FlagsUnk2 *result) {}
bool AdventureFlags::Get_FlagsUnk_18(s32 index, FlagsUnk2 *result) {}

FlagsUnk *AdventureFlags::Get_FlagsUnk(s32 index) {
    return (FlagsUnk *) (data_ov000_020e310c + index * 0x4C);
}

bool AdventureFlags::func_ov00_02097e6c() {
    return func_ov000_02098114(this->mCutsceneHandler);
}

bool AdventureFlags::func_ov00_02097e7c() {
    bool bVar1;

    bVar1 = this->func_ov00_02097e6c();
    if (bVar1) {
        bVar1 = this->mCutsceneHandler->SkipCutscene(0);
        return bVar1;
    }

    return false;
}

bool AdventureFlags::func_ov00_02097ea4() {
    bool bVar1;

    bVar1 = this->func_ov00_02097e6c();
    if (bVar1) {
        bVar1 = this->mCutsceneHandler->SkipCutscene(1);
        return bVar1;
    }

    return false;
}
unk32 AdventureFlags::func_ov00_02097ecc() {}
void *AdventureFlags::func_ov00_02097f8c() {}
void *AdventureFlags::func_ov00_02097fac() {}
void *AdventureFlags::func_ov00_02097fd0() {}
void AdventureFlags::func_ov00_02097ff4(bool param1, bool param2) {}
unk32 AdventureFlags::func_ov00_02098058() {}
bool AdventureFlags::func_ov00_02098064(unk32 param1) {}
bool AdventureFlags::func_ov00_02098074(unk32 param1, unk16 param2, unk32 param3, unk32 param4, bool param5) {}
bool AdventureFlags::func_ov00_0209809c() {}
bool AdventureFlags::func_ov00_020980ac() {}
void AdventureFlags::func_ov00_020980bc(s32 param1) {}
