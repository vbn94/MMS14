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

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort

void bubbleSort(int arr[], int n, int (*comp)(int,int)){
   for (int i = 0; i < n-1; i++){
       for (int j = 0; j < n-i-1; j++){
           if (comp(arr[j], arr[j+1]) < 0){
              swap(&arr[j], &arr[j+1]);
           }
       }
   }
}

int compInt(int a, int b){
    return b - a;
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
   // qsort(arr, COUNT, sizeof(int), compare);
   bubbleSort(arr, COUNT, compInt);
    for (int i = 0; i < COUNT; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}