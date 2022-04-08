#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define COUNT 10
#define BUFFER 10

pthread_barrier_t b;

void* walking(void* args){
    printf("Waiting on barrier...\n");
    pthread_barrier_wait(&b);
    printf("After barrier\n");
}

int main(){
    srand(time(NULL));
    pthread_t th[COUNT];
    pthread_barrier_init(&b, NULL, 2);
    for (int i = 0; i < COUNT; i++){
        if (pthread_create(th + i, NULL, walking, NULL) != 0){
            perror("create");
            return EXIT_FAILURE;
        }
    } 

    for (int i = 0; i < COUNT; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("join");
            return EXIT_FAILURE;
        }    
    }
    return EXIT_SUCCESS;
}