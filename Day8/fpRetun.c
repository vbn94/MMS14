#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}


void (*getSort(char sort))(void*, size_t, size_t, int (*)(const void*,const void*)){
    if (sort == 'q'){
        return qsort;
    } else if (sort == 'b'){
        return bubbleSort;
    }
}

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

int (*getOperation(int op))(int, int){
    if (op == 0){
        return sum;
    }
    return sub;
}

int main(){
    int (*fp)(int, int) = getOperation(0);
    int num = fp(20, 30);
    printf("%d\n", num);
    return 0;
}