#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define COUNT 1000

pthread_mutex_t incrementMux;
int num = 0;
//sem_t rc;

void* routine(void* arg){
    for (int i = 0; i < 100; i++){
        //sem_wait(&rc);
        pthread_mutex_lock(&incrementMux);
        num++; // critical section
        //sem_post(&rc);
        pthread_mutex_unlock(&incrementMux);
        usleep(5000);
    }
}

int main(){
   // sem_init(&rc, 0, 1);
    pthread_t th[COUNT];
    pthread_mutex_init(&incrementMux, NULL);
    for (int i = 0; i < COUNT; i++){
        if(pthread_create(&th[i], NULL, routine, NULL) != 0){
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
   // sem_destroy(&rc);
    pthread_mutex_destroy(&incrementMux);
    printf("Num = %d\n", num);
    return EXIT_SUCCESS;
}