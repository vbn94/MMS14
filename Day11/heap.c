#include <stdio.h>
#include <stdlib.h>

int* getNum(){
    int* num = malloc(sizeof(int));
    *num = 20;
    return num;
}

int main(){
    int* p = getNum();
    printf("%d\n", *p);
    free(p);
    return 0;
}