#include <stdio.h>

int sum(int a, int b){
    return a + b;
}


int sub(int a, int b){
    return a - b;
}

void printNum(){
    return;
}

double func(int* arr, size_t num){
    return 10;
}

int main(){
    double (*myFtr)(int*,size_t) = func;

    void (*f)(void);
    int (*fp)(int,int);
    fp = printNum;
    int num = fp(10, 20);
    printf("%d\n", num);
    fp = sub;
    num = fp(10, 20);
    printf("%d\n", num);
    printf("%p\n", fp);
    return 0;
}