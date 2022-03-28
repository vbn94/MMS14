#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

int max(int a, int b){
    return ((a)>(b)?(a):(b));
}

int main(){
    int a = 10, b = 20, c;
    a++;
    b++;
    c = MAX(a, b);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}