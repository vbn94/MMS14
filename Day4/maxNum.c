#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    double num;
    double max = DBL_MIN;
    while (scanf("%lf", &num) != EOF){
        if (num > max){
            max = num;
        }
    }
    printf("%lf\n", max);
}