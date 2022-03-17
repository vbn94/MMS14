#include <stdio.h>
#include <stdint.h>

int checkBit(uint32_t, unsigned);
void setBitP(uint32_t* ,unsigned );
void clearBitP(uint32_t*,unsigned);
void changeBitP(uint32_t*, unsigned);
uint32_t setBit(uint32_t, unsigned);
uint32_t clearBit(uint32_t, unsigned);
uint32_t changeBit(uint32_t, unsigned);

int main(){
    uint32_t mask = 0x00;
    setBitP(&mask, 5);
    setBitP(&mask, 4);
    for (int i = sizeof(uint32_t)*8 - 1; i >= 0; i--){
        printf("%d", checkBit(mask, i));
    }
    printf("\n");
    return 0;
}