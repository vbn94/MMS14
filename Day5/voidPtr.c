#include <stdio.h>
#define TINT 1
#define TDOUBLE 2

void printMax(const void* num1, const void* num2, int type){
    if (type == 1){
        int a = *((int*)num1);
        int b = *((int*)num2);
        printf("%d\n", a>b?a:b);
    } else if (type == 2){
        double a = *((double*)num1);
        double b = *((double*)num2);
        printf("%lf\n", a>b?a:b);
    }
}


int main(){
    double pi = 3.14;
    int num = 20;
    void* ptr; // universal pointer
    ptr = &num;
    printf("Num = %d\n",  *((int*)ptr));
    ptr = &pi;
    printf("Pi = %lf\n",  *((double*)ptr));
    return 0;

}