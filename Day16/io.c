#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    char buff[BUFSIZ];
    size_t bytes;
    while((bytes = read(STDIN_FILENO, buff, BUFSIZ) > 0)){
        write(STDOUT_FILENO, buff, bytes);
    }
    return 0;
}