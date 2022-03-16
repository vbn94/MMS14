#include <stdio.h>
#include <math.h>

#define EPS 0.001


int compare1(double a, double b){
    return a == b;
}

int compare2(double a, double b){
    return fabs(a - b) < __FLT_EPSILON__;
}

int compare3(double a, double b, double eps){
    return fabs(a - b) < eps;
}

int compare4(double a, double b){
    return fabs(a - b) < __FLT_EPSILON__ * fmax(fabs(a), fabs(b));
}

int main(){
    double a = 1.1;
    double b = 0;
    for (int i = 0; i < 11; i++){
        b += 0.1;
    }
    printf("a = %.30lf, b = %.30lf\n", a, b);

    if (fabs(a - b) < __FLT_EPSILON__){
        printf("a == b\n");
    } else if (a > b){
        printf("a > b\n");
    } else {
        printf("b > a\n");
    }
    return 0;

}