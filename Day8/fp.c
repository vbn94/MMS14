#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define COUNT 20

void printNum(double num){
    printf("Value = %.2lf\n", num);
}

int compare(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapg(void *a, void* b, size_t size){
    uint8_t temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}

// A function to implement bubble sort

void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*)){
   for (int i = 0; i < n-1; i++){
       for (int j = 0; j < (n-i-1) * size; j += size){
           if (comp(arr + j, arr + j + size) < 0){
              swapg(arr + j, arr + j + size, size);
              // &arr[j] => arr + j
              // &arr[j + 1] => arr + j + 1
           }
       }
   }
}

int compInt(int a, int b){
    return b - a;
}

int main(){
    char num1 = 'z', num2 = 'a';
    swapg(&num1, &num2, sizeof(char));
    printf("%c %c\n", num1, num2);
    /*void (*fp)(double);
    fp = printNum;
    fp(4.56); */
    
    srand(time(NULL));
    int arr[COUNT];
    for (int i = 0; i < COUNT; i++){
        arr[i] = rand() % 100;  // 0-99
    }
   // qsort(arr, COUNT, sizeof(int), compare);
    bubbleSort(arr, COUNT, sizeof(int), compare);
    for (int i = 0; i < COUNT; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    return 0;
}