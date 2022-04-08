#include <stdio.h>

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
    #undef OS
    #define OS 2
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
    return 0;
}