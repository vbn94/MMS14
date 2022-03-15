#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double a, b, c, P, S, p;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || b+c<=a){
        fprintf(stderr, "Invalid triangle sizes!\n");
        return EXIT_FAILURE;
    }
    P = a + b + c;
    p = P / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("P = %.2lf, S = %.2lf\n", P, S);
    return EXIT_SUCCESS;
}