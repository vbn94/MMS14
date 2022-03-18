#include <stdio.h>
#include <stdint.h>
int main(){
    /*int num = 20;
    int* ptr = &num;
    double pi = 3.141592;
    double *piPtr = &pi;
    int n = num;

    printf("Address n: %p\n", &n);
    printf("Address num: %p\n", &num);
    //printf("%lf", *piPtr);
    //printf("Address of num: %p\n", ptr);
    //printf("%d\n", *ptr);
    //printf("%d\n", *(&(*(&num))));*/

    int num = 20;
    int* ptr = &num;
    printf("Pointer: %p\n", ptr);
    int n = 45;
    ptr = &n;
    printf("Pointer: %p\n", ptr);

    printf("%lu\n", sizeof(int*));
    printf("%lu\n", sizeof(char*));
    printf("%lu\n", sizeof(double*));
    printf("%lu\n", sizeof(float*));
    printf("%lu\n", sizeof(long*));
    printf("%lu\n", sizeof(uint64_t*));
    printf("%lu\n", sizeof(uint8_t*));
    int* p = 0x1012ff;
    printf("Address: %d\n", *p);
    return 0;
}