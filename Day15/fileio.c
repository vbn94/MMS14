#include <stdio.h>
#include <errno.h>
#include <string.h>
extern int errno;

int main(){
    FILE* fp = fopen("file22.txt", "r"); // NULL
    if (NULL == fp){
        // errno, strerror(errno);
        perror("Error info");
        return 1;
    }
    int a, b;
    fscanf(fp, "%d %d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    if ( fclose(fp) == -1){
        fprintf(stderr, "Error exit file\n");
        return 1;
    }
    return 0;
}