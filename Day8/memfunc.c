#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int nums[] = { 20, 0xffffff, 40 };
    int nums2[10];
    memmove(nums2, nums, 6);
    printf("%d\n", nums2[2]);
    return 0;
}