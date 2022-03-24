#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *user = getenv("USER");
    if (strcmp(user, "vnachev") != 0){
         printf("You dont have access here!\n");
         return EXIT_FAILURE;
    }
    printf("Hello to my program!\n");
    return EXIT_SUCCESS;
}