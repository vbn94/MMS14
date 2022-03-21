#include <stdio.h>
#define COUNT 5

int sumArr(int* arr, size_t n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += *(arr + i);
    }
    return sum;
}

int maxNum(int* arr, size_t n){
    int max = *arr;
    for (int i = 1; i < n; i++){
        max = (*(arr + i) > max) ? *(arr + i) : max;
    }
    return max;
}
// min, average 17:00

int main(){
    // int[] nums;
    int nums[COUNT];
   /* 
    for (int i = 0; i < COUNT; i++){
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < COUNT; i++){
        printf("nums[%d] = %d\n", i, i[nums]);
    }
    */
    for (int i = 0; i < COUNT; i++){
        scanf("%d", nums + i);
    }
    for (int i = 0; i < COUNT; i++){
        printf("nums[%d] = %d\n", i, *(i + nums));
    }

    printf("Sum = %d\n", sumArr(nums, COUNT));
    return 0;
}