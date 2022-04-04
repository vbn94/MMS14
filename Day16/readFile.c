#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1){
        perror("error info: ");
        return EXIT_FAILURE;
    }
    printf("File descriptor: %d\n", fd);
    char buff[BUFSIZ];
    size_t bytes;
    while (bytes = read(fd, buff, BUFSIZ)){
        write(STDOUT_FILENO, buff, bytes);
    }
    close(fd);
    return 0;
}