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
        char *args[] = { "mkdir", "dir4", "dir2", "dir3", NULL };
        execpv("mkdir", args);
    } else {
        // parent is here
        int status;
        wait(&status);
        WIFEXITED(status);
        printf("Exit code: %d\n", WEXITSTATUS(status));
    }
    return 0;
}