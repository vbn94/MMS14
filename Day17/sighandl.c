#define  _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void func(){
    printf("Multiplication first!\n");
}

int main(){
    pid_t pid = fork();
    if (0 == pid){
        sleep(5);
        kill(getppid(), SIGUSR1);
    } else {
        struct sigaction sa;
        sa.sa_handler = func;
        sa.sa_flags = SA_RESTART;
        sigaction(SIGUSR1, &sa, NULL);

        printf("5 + 2 * 3 = ?\n");
        int num;
        scanf("%d", &num);
        if (11 == num){
            printf("Super...\n");
        } else {
            printf("Try again...\n");
        }
        kill(pid, SIGTERM);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}