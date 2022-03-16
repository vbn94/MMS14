#include <stdio.h>
#include <stdint.h>

int main(){

    int8_t a = 10;
    uint16_t b = 20;
    uint32_t c = 30;
    uint64_t d = 30;
    uint8_t e = 3;


    int32_t number = -1;
    printf("Number = %u\n", number);
    long num = 1;
    /*while(num > 0){
        printf("%ld\n", num);
        num += 1000;
    }
    printf("%d\n", num);
    printf("Bye bye\n");*/
    printf("Size of int: %ld Bytes\n", sizeof(int));
    printf("Size of unsigned: %ld Bytes\n", sizeof(unsigned));
    printf("Size of long: %ld Bytes\n", sizeof(long));
    printf("Size of ulong: %ld Bytes\n", sizeof(unsigned long));
    printf("Size of short: %ld Bytes\n", sizeof(short));
    printf("Size of ushort: %ld Bytes\n", sizeof(unsigned short));
    printf("Size of char: %ld Bytes\n", sizeof(char));
    printf("Size of num: %ld Bytes\n", sizeof(num));
    printf("Size of intX_t %ld Bytes\n", sizeof(uint64_t));
    printf("Size of float %ld Bytes\n", sizeof(float));
    printf("Size of double %ld Bytes\n", sizeof(double));
    printf("Size of long double %ld Bytes\n", sizeof(long double));
    return 0;
}