#include <stdio.h>
#include <stdlib.h>
int globalvar = 10;

int main(){
    int num;
    scanf("%d", &num);
    //int* arr = malloc(sizeof(int) * num);
    int* arr = calloc(num, sizeof(int)); // 0000000000000000000000000
    arr = realloc(arr, 2 * num * sizeof(int));
    for (int i = 0; i < num; i++){
        arr[i] = i;
    }
    for (int i = 0; i < num; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr); // realloc(arr, 0);
    return 0;
}