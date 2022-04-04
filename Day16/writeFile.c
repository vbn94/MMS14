#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    //int fcreate = creat("file1.txt", 0777);
    int fd = creat("file.txt", 0777);
    if (fd < 0){
        perror("error");
        return EXIT_FAILURE;
    }
    char buff[BUFSIZ];
    size_t n;
    while ((n = read(STDIN_FILENO, buff, BUFSIZ)) > 0){
        if(write(fd, buff, n) == -1){
            perror("error");
            return EXIT_FAILURE;
        }
    }
    close(fd);
    fd = open("file.txt", O_RDONLY);
    printf("\nFile:\n\n");
    while ((n = read(fd, buff, BUFSIZ)) > 0){
        if(write(STDOUT_FILENO, buff, n) == -1){
            perror("error");
            return EXIT_FAILURE;
        }
    }
    lseek(fd, 0, SEEK_SET);
    printf("\nFile:\n\n");
    while ((n = read(fd, buff, BUFSIZ)) > 0){
        if(write(STDOUT_FILENO, buff, n) == -1){
            perror("error");
            return EXIT_FAILURE;
        }
    }
    return 0;
}