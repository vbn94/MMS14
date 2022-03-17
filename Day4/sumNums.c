#include <stdio.h>

int main(){
    int num;
    int sum = 0;
    while (scanf("%d", &num) != EOF){
        sum += num;
    }
    printf("%d\n", sum);
}