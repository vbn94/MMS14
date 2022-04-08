#include <stdio.h>
#include "mymath.h"

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int result = sum(a, b);
    printf("Result = %d\n", result);
    return 0;
}
