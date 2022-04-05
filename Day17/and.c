#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int forkExecute(const char* cmd){
    pid_t pid = fork();
    if (0 == pid){
        if(-1 == execlp(cmd, cmd, NULL)){
            perror("execlp:");
            exit(EXIT_FAILURE);
        }
    } else if (-1 == pid){
        perror("fork:");
        exit(EXIT_FAILURE);
    }
    int status;
    if(-1 == wait(&status)){
        perror("wait");
        exit(EXIT_FAILURE);
    }
    return WEXITSTATUS(status);
}

int main(int argc, char **argv){
    int exitstatus;
    for (int i = 1; i < argc; i++){
        exitstatus = forkExecute(argv[i]);
        if (EXIT_SUCCESS == exitstatus){
            return exitstatus;
        }
    }
    return EXIT_SUCCESS;
}