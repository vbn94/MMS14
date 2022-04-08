#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    if (0 == pid){
        while (1){
            printf("Red ON\n");
            sleep(2);
            printf("Red OFF\n");
            sleep(2);
        }
    } else {
        pid_t pid2 = fork();
        if (0 == pid2){
            while (1){
                // read button 
                kill(); // red blink
                kill(); // while b
            }
        } else {
            while (1){
                printf("Green ON\n");
                sleep(1);
                printf("Green OFF\n");
                sleep(1);
            }
        }
    }
    return EXIT_SUCCESS;
}