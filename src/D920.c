#include "common.h"

s32 func_8010D9B4(void);
void func_8010D9C0(s32);

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

INCLUDE_ASM("asm/nonmatchings/D920", func_8010C9C0);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010C9FC);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CA44);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CA84);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CB60);

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
