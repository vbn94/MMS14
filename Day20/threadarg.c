#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define COUNT 1

int nums[] = { 10, 20, 30, 40, 50 };

void* routine(void* arg){
    sleep(1);
    int index = *(int*)arg;
    printf("Number: %d\n", nums[index]);
    printf("Pointer in thread %p\n", arg);
    free(arg);
}

int main(){
    pthread_t th[COUNT];

    for (int i = 0; i < COUNT; i++){
        int* num = malloc(sizeof(int));
        *num = i; 
        printf("Pointer before thread %p\n", num);
        if(pthread_create(th + i, NULL, routine, num)){
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
    return EXIT_SUCCESS;
}