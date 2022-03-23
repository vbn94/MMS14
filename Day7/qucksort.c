#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* num1, const void* num2){
    return *(int*)num1 - *(int*)num2;
}

int main(){
    int nums[] = {103, 203, -4, 534, 18, 90, -1};
    qsort(nums, 7, sizeof(nums[0]), compare);
    for (int i = 0; i < 7; i++){
        printf("%d ", nums[i]);
    }
    putchar('\n');
    int key = -4;
    int* n = bsearch(&key, nums, 7, sizeof(nums[0]), compare);
    if (n == NULL){
        printf("Not found\n");
    } else {
        int index = ((long unsigned)n - (long unsigned)nums) / sizeof(int);
        printf("Index = %d\n", index);
        printf("Num = %d\n", nums[index]);
    }
    return 0;
}