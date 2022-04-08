#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int num = 20;

void* routune1(void* arg){
    for (int i = 0; i < 10; i++){
        num++;
        sleep(1);
    }
}

void* routune2(void* arg){
    for (int i = 0; i < 10; i++){
        printf("Num = %d\n", num);
        sleep(1);
    }
}

int main(){
    pthread_t th1, th2;
    if(pthread_create(&th1, NULL, routune2, NULL) != 0){
        perror("pthread create");
    }
    if(pthread_create(&th2, NULL, routune2, NULL) != 0){
        perror("pthread create");
    }
    if (pthread_join(th1, NULL) != 0){
        perror("pthread join");
    }
    if (pthread_join(th2, NULL) != 0){
        perror("pthread join");
    }
    return EXIT_SUCCESS;
}