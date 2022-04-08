#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define COUNT 5

void* dice(void* arg){
    int *val = malloc(sizeof(int));
    *val = 1 + rand() % 6; // [1;6]
    return val;
}

int main(){
    srand(time(NULL));
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        if(pthread_create(th + i, NULL, dice, NULL)){
            perror("create error");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < COUNT; i++){
        int* value;
        if(pthread_join(th[i], (void**)&value)){
            perror("join error");
            return EXIT_FAILURE;
        }
        printf("Dice value: %d\n", *value);
        free(value);
    }
    return EXIT_SUCCESS;
}