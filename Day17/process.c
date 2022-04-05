#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork problem");
        return EXIT_FAILURE;
    } else if (0 == pid){
        // child is here
        for (int i = 0; i < 10; i++){
            printf("Hello, I'm child!\n");
            sleep(1);
        }
        printf("I'm child: PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // parent is here
        for (int i = 0; i < 10; i++){
            printf("Hello, I'm parent!\n");
            sleep(1);
        }
        printf("I'm parent: PID: %d, PPID: %d\n", getpid(), getppid());
        wait(NULL);
    }
    return 0;
}