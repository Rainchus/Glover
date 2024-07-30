#include "common.h"

#define UNK_KSEG1_0 (u32*)0xB1FFFFDC
#define UNK_KSEG1_1 (u32*)0xB1FFFFE0
#define UNK_KSEG1_2 (u32*)0xB1FFFFE4
#define UNK_KSEG1_3 (u32*)0xB1FFFFE8
#define UNK_KSEG1_4 (u32*)0xB1FFFFEC
#define UNK_KSEG1_5 (u32*)0xB1FFFFF0

void func_8010C988(u32*, u32);
u32 func_8010C9C0(u32*);
void func_8010C9FC(s32);
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

void func_8010C988(u32* arg0, u32 arg1) {
    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {}
    *arg0 = arg1;
}

u32 func_8010C9C0(u32* arg0) {
    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {}
    return *arg0;
}

void func_8010C9FC(s32 arg0) {
    for (D_801F5680 = 0; D_801F5680 < arg0; D_801F5680++) {}
}

u8 func_8010CA44(u32* arg0) { //segmented pointer maybe?
    u32 temp = (~(u32)arg0 & 3) * 8;
    u32 temp2;

    temp2 = func_8010C9C0((u32*)((u32)arg0 & ~0x3));
    temp2 = temp2 >> temp;
    
    return temp2;
}

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CA84);

void WriteByteReversedEndianess(u32* arg0, u32 arg1) {
    u32* temp_a0;
    u32 temp_a2;

    temp_a2 = ((~(u32)arg0) % 4) * 8;
    temp_a0 = (u32*) ((u32)arg0 & ~3);
    *temp_a0 = ((*temp_a0 & (~(0xFF << temp_a2))) | ((arg1 & 0xFF) << temp_a2));
}

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CB9C);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CCB0);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CD28);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CE14);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CEE0);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010CF54);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D104);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D170);

void func_8010D39C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_8010C988(UNK_KSEG1_2, arg1);
    func_8010C988(UNK_KSEG1_3, arg2);
    func_8010C988(UNK_KSEG1_4, arg3);
    func_8010C988(UNK_KSEG1_1, arg0);
    do {
        func_8010C9FC(1000);
        if (func_8010C9C0(UNK_KSEG1_5) != 0) {
            func_8010C988(UNK_KSEG1_1, 0);
            __asm__("break 0x1"); //__asm__("break 0x400"); (matches when SN64 compiler is used (currently using wrong compiler, kmc gcc))
            func_8010C988(UNK_KSEG1_1, arg0);
        }
    } while (func_8010C9C0(UNK_KSEG1_1) != 0);
    func_8010C9C0(UNK_KSEG1_0);
}

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D470);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D490);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D4DC);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D56C);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D5FC);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D664);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D728);

INCLUDE_ASM("asm/nonmatchings/D920", func_8010D7F0);
