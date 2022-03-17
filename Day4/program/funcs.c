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
