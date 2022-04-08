#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define COUNT 10

pthread_mutex_t wcMutex;

void* routine(void* arg){
    sleep(1);
    printf("Hello\n");
    pthread_mutex_lock(&wcMutex);
    printf("I'm in WC!\n");
    sleep(1);
    pthread_mutex_unlock(&wcMutex);
    printf("Bye bye\n");
}

int main(){
    pthread_t th[COUNT];
    pthread_mutex_init(&wcMutex, NULL);
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
    pthread_mutex_destroy(&wcMutex);
    return EXIT_SUCCESS;
}