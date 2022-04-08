#define  _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void hint(int a){
    printf("Multiplication first!\n");
}

int main(){
    pid_t pid = fork();
    if (0 == pid){
        sleep(5);
        kill(getppid(),SIGUSR1);
    } else {
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = hint;
        sigaction(SIGUSR1, &sa, NULL);
        printf("3+1x4 = ?\n");
        int result;
        scanf("%d", &result);
        if (result == 7){
            printf("Super\n");
        } else {
            printf("Error\n");
        }
        kill(pid ,SIGTERM);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}