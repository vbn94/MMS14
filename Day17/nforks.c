#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define COUNT 5
int main(){
    for (int i = 0; i < COUNT; i++){
        pid_t pid = fork();
        if (0 == pid){
            printf("Hello\n");
            
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < COUNT; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}