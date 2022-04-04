#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC);
    dup2(fd, STDOUT_FILENO);
    printf("Hello\n");
    printf("12345\n");
    printf("MMS C Camp\n");
    close(fd);
    return 0;
}