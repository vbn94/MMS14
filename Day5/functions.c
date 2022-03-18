#include <stdio.h>
#include <stdlib.h>

void printHello(void);
int getNum(void);
int sum(int,int);
double max(double,double);
void setZero(int*);
void swapNums(int*,int*);


void setValues(int* num1, double* num2){
    *num1 = 180;
    *num2 = 3.14;
}
int rectangle(double,double,double*,double*);

int triangle(double,double,double,double*,double*);


int main(void){
    double w, h, per, area;
    while (scanf("%lf %lf", &w, &h) != EOF){
        if (rectangle(w, h, &per, &area) == -1){
            fprintf(stderr, "Invalid sides\n");
        } else {
            printf("P = %.2lf, S = %.2lf\n", per, area);
        }
    }
/*
    //printHello();
    int a = 150, b = 200;
    printf("a = %d, b = %d\n", a, b);
    swapNums(&a, &b);
    printf("a = %d, b = %d\n", a, b);*/
    return EXIT_SUCCESS;
}

int rectangle(double w, double h, double* P, double* S){
    if (w <= 0 || h <= 0){
        return -1;
    }
    *P = 2 * (w + h);
    *S = w * h;
    return 0;
}

void swapNums(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void setZero(int* num){
    *num = 0;
}
int sum(int num1, int num2){
    return num1 + num2;
}

void printHello(void){
    printf("Hello\n");
   // return;
    printf("Bye bye\n");
}

int getNum(){
    return 50;
}

double max(double num1, double num2){
    if (num1 > num2){
        return num1;
    } 
    return num2;
}