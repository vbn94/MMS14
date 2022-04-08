#include <stdio.h>
#define TINT 1
#define TDOUBLE 2
#define DEBUG
#ifdef DEBUG
    #define LOG(x) printf("%d\n", x)
#else
    #define LOG(x)
#endif

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
    int num = 20, num2 = 30;
    LOG(num);
    LOG(num2);
    return 0;

}