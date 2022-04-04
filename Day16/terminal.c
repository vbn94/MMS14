#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fd = open("/dev/pts/1", O_WRONLY);
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
    return 0;
}