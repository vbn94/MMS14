#include <stdio.h>

int global = 0;

int f1(int x){
    return x * 10;
}

// f(1) -> 10,   f(1) -> 50

int doubleNum(int x){
    return 2 * x;
}



void printNum(){
    static int n = 0;
    n++;
    printf("%d\n", n);
}

int array[] = {20, 30, 40, 50};

void printNextElement(){
    static int i;
    printf("array[%d] = %d\n", i, array[i]);
    i++;
}

int main(){
    printNextElement();
    printNextElement();
    printNextElement();
    return 0;
}