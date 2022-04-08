
#include <stdio.h>
#include "funcs.h"

extern int x;

/*static void printHello(){
    printf("Hello MMS\n");
}*/
volatile int count = 0;

void inc(){
    count++;
}

void func(){
    count = 0;
    // count <------ ISR -> inc() => count = 1
    if (count == 0){
        printf("Nesto");
    }
    // printf("Nesto");
}

int main(){
    for (register int i = 0; i < 10; i++){
        printf("%d\n", i);
    }
    return 0;
}