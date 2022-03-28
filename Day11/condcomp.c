#include <stdio.h>

// #define DEBUG
#define OS 1

int main(){

    #ifdef OS
        #if OS == 1 
            printf("Linux\n");
        #elif OS == 2
            printf("Windows\n");
        #else
            printf("macOS\n");
        #endif
    #else
        printf("OS is undefined...\n");
    #endif
    printf("Bye bye!\n");
    return 0;
}