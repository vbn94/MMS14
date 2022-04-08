#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define COUNT 12

pthread_barrier_t b;

void* walking(void* args){
    printf("Waiting for belot...\n");
    pthread_barrier_wait(&b);
    printf("Playng belot %ld\n", pthread_self());
}

int main(){
    srand(time(NULL));
    pthread_t th[COUNT];
    pthread_barrier_init(&b, NULL, 4);
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
    pthread_barrier_destroy(&b);
    return EXIT_SUCCESS;
}