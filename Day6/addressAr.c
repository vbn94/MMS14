#include <stdio.h>

int main(){
    short *p = 0x00;
    printf("%lu\n", (unsigned long)p);
    printf("%lu\n", (unsigned long)(p + 1));
    printf("%lu\n", (unsigned long)(p + 2));
    return 0;
}