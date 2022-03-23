#include <stdio.h>

void changeArr(int* arr, size_t n, int (*func)(int)){
    for (int i = 0; i < n; i++){
        arr[i] = (*func)(arr[i]);
    }
}

int doubleNum(int num){
    return num * 2;
}

int inc(int num){
    return num + 1;
}

int main(){
    int arr[] = {20, 30, 50, 100};
    changeArr(arr, 4, inc);
    for (int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}