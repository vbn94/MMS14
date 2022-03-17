#include <stdio.h>
#include <stdint.h>

int checkBit(uint32_t mask, unsigned bit){
    return !!(mask & (1 << bit));
}

void setBitP(uint32_t* mask, unsigned bit){
    *mask |= (1 << bit);
}
void clearBitP(uint32_t* mask, unsigned bit){
    *mask &= ~(1 << bit);
}

void changeBitP(uint32_t* mask, unsigned bit){
    *mask ^= (1 << bit);
}


uint32_t setBit(uint32_t mask, unsigned bit){
    return mask | (1 << bit);
}

uint32_t clearBit(uint32_t mask, unsigned bit){
    return mask & ~(1 << bit);
}

uint32_t changeBit(uint32_t mask, unsigned bit){
    return mask ^ (1 << bit);
}

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