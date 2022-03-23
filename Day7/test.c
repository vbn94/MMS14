#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

size_t mystrlen(const char* str){
    size_t cnt = -1;
    while (*(str + ++cnt));  // str[++cnt]
    return cnt;
}

void printValue(const int *num){
    printf("Value: %d\n", *num);
}

char* mystrcpy(char* dest, const char* src){
    if (dest == NULL){
        return NULL;
    }
    int i = 0;
    while (src[i]){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* mystrncpy(char* dest, const char* src, size_t n){
    if (dest == NULL){
        return NULL;
    }
    int i = 0;
    while (src[i] && i < n){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int myatoi(const char* str, int *res){
    int num = 0, coeff = 1, end = 0;
    if (*str == '-'){
        coeff = -1;
        end = 1;
    }
    for (int i = strlen(str) - 1, n = 1; i >= end; i--, n *= 10){
            if (str[i] < '0' || str[i] > '9'){
                return 1;
            }
            num += n * (str[i] - '0');
    }
    *res = num * coeff;
    return 0;
}

int main(){
    /*char str[100];
    strcpy(str, "205");
    int num = atoi(str);
    printf("Num = %d\n", num);
    strcpy(str, "-45.6");
    double realNum = atof(str);
    printf("Real num = %lf\n", realNum);*/

    /*char str[100], out[100];
    strcpy(str, "13 223 34");
    int num1, num2, num3;
    double pi;
    sscanf(str, "%d %d %d", &num1, &num2, &num3);
    sprintf(out, "Num1 = %d", num1);
    printf("String: %s\n", out);
    //printf("Num2 = %d\n", num2);
    //printf("Num3 = %d\n", num3);*/

    char str[20];
    strcpy(str, "-55$8");
    int num;
    if(!myatoi(str, &num)){
        printf("Number: %d\n", num);
    } else {
        printf("Error parse!\n");
    }

    return 0;
}