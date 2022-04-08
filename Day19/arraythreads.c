#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define COUNT 10

void* routine(void* arg){
    printf("Hello\n");
    sleep(2);
    printf("Bye bye\n");
}

int main(){
    pthread_t th[COUNT];

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

    return EXIT_SUCCESS;
}