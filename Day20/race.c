#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define COUNT 50
pthread_mutex_t mux;

int num = 0;

void* inc(void* arg){
    for (int i = 0; i < 1000; i++){
        pthread_mutex_lock(&mux);
        num++; // critical section
        pthread_mutex_unlock(&mux);
        usleep(10000);
    }
}

int main(){
    srand(time(NULL));
    pthread_mutex_init(&mux, NULL);
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        if(pthread_create(th + i, NULL, inc, NULL)){
            perror("create error");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < COUNT; i++){
        if(pthread_join(th[i], NULL)){
            perror("join error");
            return EXIT_FAILURE;
        }
    }
    pthread_mutex_destroy(&mux);
    printf("Num = %d\n", num);
    return EXIT_SUCCESS;
}