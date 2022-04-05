#define  _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void func(){
    printf("I' dont want to die!\n");
}

int main(){
    struct sigaction sa;
    sa.sa_handler = func;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);

    while(1){

    }

    return EXIT_SUCCESS;
}