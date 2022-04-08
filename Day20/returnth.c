#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define COUNT 5
int num = 0;
void* inc(void* arg){
    for (int i = 0; i < 1000; i++){
        num++;
        usleep(100);
    }
}

int main(){
    srand(time(NULL));
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        if(pthread_create(th + i, NULL, inc, NULL)){
            perror("create error");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < COUNT; i++){
        if(pthread_join(th[i], NULL){
            perror("join error");
            return EXIT_FAILURE;
        }
    }

    printf("Num = %d\n", num);
    return EXIT_SUCCESS;
}