#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC);
    int fd2 = dup(fd);
    char buff[BUFSIZ];
    size_t n;
    while ((n = read(STDIN_FILENO, buff, BUFSIZ)) > 0){
        if(write(fd2, buff, n) == -1){
            perror("error");
            return EXIT_FAILURE;
        }
    }
    close(fd);
    close(fd2);
    return 0;
}