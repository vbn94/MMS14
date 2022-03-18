#include <stdio.h>
#include <stdarg.h>

#define TINT 1
#define TDOUBLE 2
#define TFLOAT 3
#define TCHAR 4

void printValue(const void* val, int flag){
    if (flag == TINT){
        printf("Value: %d\n", *((int*)val));
    } else if (flag == TDOUBLE){
        printf("Value: %lf\n", *((double*)val));
    } else if (flag == TFLOAT){
        printf("Value: %f\n", *((float*)val));
    } else if (flag == TCHAR){
        printf("Value: %c\n", *((char*)val));
    }
}

int addNums(int n, ...){
    int sum = 0;
    va_list ptr, ptr2;
    va_start(ptr, n);
    va_copy(ptr2, ptr);
    for(int i = 0; i < n; i++){
        sum += va_arg(ptr, int);
    }
    va_end(ptr);
    for(int i = 0; i < n; i++){
        sum += va_arg(ptr2, int);
    }
    va_end(ptr2);
    return sum;
}

int main(){
    int nn = 33;
    int num = 15;
    double rnum = 3.14;
    float fnum = 3.14F;
    char c = 'z';
    printValue(&nn, TINT);
    printValue(&num, TINT);
    printValue(&rnum, TDOUBLE);
    printValue(&fnum, TFLOAT);
    printValue(&c, TCHAR);
        printValue(&num, TINT);
    return 0;
}