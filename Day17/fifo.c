#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(){
    if(mkfifo("myfifo", 0777) == -1){
        if(errno != EEXIST){
            perror("error:");
            return EXIT_FAILURE;
        }
    }
    printf("Opening...\n");
    int fifo = open("myfifo", O_WRONLY);
    printf("Opened\n");
    char *str = "Hello";
    write(fifo, str, 6);
    printf("Written\n");
    close(fifo);
    printf("Closed\n");
    return 0;
}