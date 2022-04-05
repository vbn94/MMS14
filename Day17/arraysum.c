#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int arr[] = { 1, 1, 1, 2, 2, 2 };
    int len = sizeof(arr) / sizeof(*arr);

    pid_t pid = fork();
    int end, start;
    if (-1 == pid){
        perror("fork error");
        return EXIT_FAILURE;
    } else if (0 == pid){
        // child
        start = 0;
        end = len / 2;
    } else {
        // parent
        start = len / 2;
        end = len;
    }
    int sum = 0;
    for (int i = start; i < end; i++){
        sum += arr[i];
    }
    if (pid > 0){
        wait(NULL);
    }
    printf("Sum = %d\n", sum);
    return EXIT_SUCCESS;
}