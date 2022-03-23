#include <stdio.h>

int main(int argc, char *argv[], char *env[]){
    printf("Arguments count: %d\n", argc);
    for (int i = 0; argv[i] != NULL; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    printf("Env vars: \n\n");
    for (int i = 0; env[i] != NULL; i++){
        printf("env[%d] = %s\n", i, env[i]);
    }
    return 0;
}