#include <stdio.h>

double sum(double num1, double num2){
    return num1 + num2;
}

double sub(double num1, double num2){
    return num1 - num2;
}

double mult(double num1, double num2){
    return num1 * num2;
}

double div(double num1, double num2){
    return num1 / num2;
}

int main(){
    double (*fcalc[4])(double,double) = { sum, sub, mult, div };
    int n;
    do{
        scanf("%d", &n);
    } while (n < 0 || n > 3);
    double result = fcalc[n](10.0, 20);
    printf("Result = %.2lf\n", result);
    return 0;
}