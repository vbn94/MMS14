#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 20

void printNum(double num){
    printf("Value = %.2lf\n", num);
}

int compare(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

int main(){
    /*void (*fp)(double);
    fp = printNum;
    fp(4.56); */
    srand(time(NULL));
    int arr[COUNT];
    for (int i = 0; i < COUNT; i++){
        arr[i] = rand() % 100;  // 0-99
    }
    // lambda
    qsort(arr, COUNT, sizeof(int), [](const void* a, const void* b){return *(int*)a - *(int*)b; });
    for (int i = 0; i < COUNT; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}