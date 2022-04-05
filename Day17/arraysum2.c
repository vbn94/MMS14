#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int global;

int main(){
    int arr[] = { 1, 1, 1, 2, 2, 2 };
    int len = sizeof(arr) / sizeof(*arr);

    int fd[2];
    if(pipe(fd) == -1){
        perror("pipe error");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    int end, start;
    if (-1 == pid){
        perror("fork error");
        return EXIT_FAILURE;
    } else if (0 == pid){
        // child
        close(fd[0]);
        start = 0;
        end = len / 2;
        int sum = 0;
        for (int i = start; i < end; i++){
            sum += arr[i];
        }
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    } else {
        close(fd[1]);
        // parent
        start = len / 2;
        end = len;
        int sum = 0;
        for (int i = start; i < end; i++){
            sum += arr[i];
        }
        int sumChild;
        read(fd[0], &sumChild, sizeof(sumChild));
        close(fd[0]);
        printf("Sum of parent = %d\n", sum);
        printf("Sum of child = %d\n", sumChild);
        printf("Total = %d\n", sum + sumChild);
        wait(NULL);
    }    
    return EXIT_SUCCESS;
}