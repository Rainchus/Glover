#include "common.h"

s32 func_8010D9B4(void);
void func_8010D9C0(s32);
extern volatile s32 D_801F5680;

s32 func_8010C920(void) {
    s32 temp_v0;

    temp_v0 = func_8010D9B4();
    func_8010D9C0(temp_v0 & ~1);
    return temp_v0 & 1;
}

void func_8010C958(s32 arg0) {
    func_8010D9C0(func_8010D9B4() | arg0);
}

void func_8010C988(s32* arg0, s32 arg1) {
    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {}
    *arg0 = arg1;
}

s32 func_8010C9C0(u32* arg0, u32 arg1) {
    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {}
    return *arg0;
}

void func_8010C9FC(s32 arg0) {
    for (D_801F5680 = 0; D_801F5680 < arg0; D_801F5680++) {}
}

u8 func_8010CA44(u32* arg0, u32 arg1) { //TODO: figure this out (this has to be a pointer but does non pointer operations?)
    u32 temp = (~(u32)arg0 & 3) << 3;
    u32 temp2;

    temp2 = func_8010C9C0((u32*)((u32)arg0 & ~0x3), arg1);
    temp2 = temp2 >> temp;
    
    return temp2;
}

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CA84);

void func_8010CB60(u32* arg0, u32 arg1) { //TODO: figure this out
    u32* temp_a0;
    u32 temp_a2;

    temp_a2 = (~(u32)arg0 & 3) << 3;
    temp_a0 = (u32*) ((u32)arg0 & ~3);
    *temp_a0 = ((*temp_a0 & ~(0xFF << temp_a2)) | ((arg1 & 0xFF) << temp_a2));
}

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CB9C);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CCB0);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CD28);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CE14);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CEE0);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CF54);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D104);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D170);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D39C);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D470);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D490);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D4DC);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D56C);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D5FC);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D664);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D728);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D7F0);
