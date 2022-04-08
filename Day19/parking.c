#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define COUNT 10

sem_t parkPlaces;

void* parking(void* arg){
    printf("Waiting for parinking...\n");
    sem_wait(&parkPlaces);
    sleep(1);
    printf("Car is #%d in the parking...\n", *(int*)arg);
    sleep(1 + rand() % 3);
    sem_post(&parkPlaces);
    printf("Out of parinking...\n");
    free(arg);
}

int main(){
    srand(time(NULL));
    sem_init(&parkPlaces, 0, 10);
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        int* num = malloc(sizeof(int));
        *num = i;
        if(pthread_create(&th[i], NULL, parking, num) != 0){
            perror("create thread:");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < COUNT; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("join thread:");
            return EXIT_FAILURE;
        }
    }
    sem_destroy(&parkPlaces);
    return EXIT_SUCCESS;
}