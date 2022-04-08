#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define COUNT 4

int fuel = 0;

pthread_mutex_t mux;
pthread_cond_t fuelCond;

void* fill(void* args){
    while (1){
        sleep(1);
        pthread_mutex_lock(&mux);
        fuel++;
        pthread_mutex_unlock(&mux);
        //pthread_cond_signal(&fuelCond);
        pthread_cond_broadcast(&fuelCond); 
    }
}

void* get(void* args){
    while(1){
        pthread_mutex_lock(&mux);
        while (fuel < 10){
            pthread_cond_wait(&fuelCond, &mux);
        }
        fuel -= 10;
        printf("Left: %d\n", fuel);
        pthread_mutex_unlock(&mux);
    }
}

int main(){
    srand(time(NULL));
    pthread_cond_init(&fuelCond, NULL);
    pthread_mutex_init(&mux, NULL);
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        if (i % 2 == 0){
            if (pthread_create(th + i, NULL, fill, NULL) != 0){
                perror("create");
                return EXIT_FAILURE;
            }
        } else {
            if (pthread_create(th + i, NULL, get, NULL) != 0){
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
    pthread_cond_destroy(&fuelCond);
    return EXIT_SUCCESS;
}