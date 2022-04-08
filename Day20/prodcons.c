#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define COUNT 10
#define BUFFER 10

int buffer[BUFFER];
int i = 0;

sem_t freePos;
sem_t busyPos;
pthread_mutex_t mux;


void* producer(void* args){
    while (1){
        int x = rand() % 20;
        sleep(1);
        sem_wait(&freePos);
        pthread_mutex_lock(&mux);
        buffer[i++] = x;
        pthread_mutex_unlock(&mux);
        sem_post(&busyPos);
    }
}

void* consumer(void* args){
    while(1){
        int x;
        sleep(1);
        sem_wait(&busyPos);
        pthread_mutex_lock(&mux);
        x = buffer[--i];
        pthread_mutex_unlock(&mux);
        sem_post(&freePos);
        printf("Thread: %ld Consumed: %d\n", pthread_self(), x);
    }
}

int main(){
    srand(time(NULL));
    sem_init(&freePos, 0, BUFFER);
    sem_init(&busyPos, 0, 0);
    pthread_mutex_init(&mux, NULL);
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        if (i == 0){
            if (pthread_create(th + i, NULL, producer, NULL) != 0){
                perror("create");
                return EXIT_FAILURE;
            }
        } else {
            if (pthread_create(th + i, NULL, consumer, NULL) != 0){
                perror("create");
                return EXIT_FAILURE;
            }
        }
    } 

    for (int i = 0; i < COUNT; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("join");
            return EXIT_FAILURE;
        }    
    }
    pthread_mutex_destroy(&mux);
    sem_destroy(&freePos);
    sem_destroy(&busyPos);
    return EXIT_SUCCESS;
}