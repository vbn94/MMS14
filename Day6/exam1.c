#include <stdio.h>
#include <stdarg.h>

unsigned count1(int mask){
    int cnt = 0;
    /*for (int i = 0; i < sizeof(int) * 8; i++){
        cnt += !!(mask & (1 << i));
    }*/
    while (mask){
        cnt += mask & 1;
        mask >>= 1;
    }
    return cnt;
}


unsigned bitsNCount(unsigned count, unsigned bitscnt, ...){
    unsigned cnt = 0;
    va_list args;
    va_start(args, bitscnt);
    for (int i = 0; i < count; i++){
        int mask = va_arg(args, int);
        /*if (count1(mask) == bitscnt){
            cnt++;
        }*/
        cnt += (count1(mask) == bitscnt);
    }
    va_end(args);
    return cnt;
}

int main(){
    printf("%u\n", count1(0b110));  // 2
    printf("%u\n", count1(0b100101));  // 3
    printf("%u\n", count1(0xf));    // 4
    printf("%u\n", count1(0b111101));  // 5
    printf("%u\n", bitsNCount(3, 8, 0xff, 0x13f1, 0xafaa));
    return 0;
}