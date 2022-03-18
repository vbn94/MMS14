#include <stdio.h>
#include <stdarg.h>

#define TINT 1
#define TDOUBLE 2
#define TCHAR 3

int sumNums(int count, ...){
    int sum = 0;
    va_list ap;
    va_start(ap, count);
    /*for (int i = 0; i < count; i++){
        sum += va_arg(ap, int);
    }*/
    int cnt = 0;
    while (cnt < count){
        sum += va_arg(ap, int);
        cnt++;
    }
    va_end(ap);
    return sum;
}


double average(int count, ...){
    double sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++){
        sum += va_arg(args, double);
    }
    va_end(args);
    return sum / count;
}

// type: 1->int, 2->double, 3->char
void printNums(int type, int count, ...){
    va_list args, args2;
    va_start(args, count);
    va_copy(args2, args);
    for (int i = 0; i < count; i++){
        if (type == 1){
            int num = va_arg(args, int);
            printf("%d ", num);
        } else if (type == 2){
            double num = va_arg(args, double);
            printf("%lf ", num);
        } else if (type == 3){
            int num = va_arg(args, int);
            printf("%c ", num);
        }
    }
    va_end(args);
    printf("\n");
    for (int i = 0; i < count; i++){
        if (type == 1){
            int num = va_arg(args2, int);
            printf("%d ", num);
        } else if (type == 2){
            double num = va_arg(args2, double);
            printf("%lf ", num);
        } else if (type == 3){
            int num = va_arg(args2, int);
            printf("%c ", num);
        }
    }
    va_end(args2);
    printf("\n");
    
}

int main(){
    int result = sumNums(4, 2, 4, 5, 6);
    printf("Result = %d\n", result);
    printNums(TCHAR, 4, 'a', 'b', 'r', 's');
    return 0;
}