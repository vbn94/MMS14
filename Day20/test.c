#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

sem_t printerSem;

#define COUNT 10

void* printer(void* arg){
    printf("%d Waiting for printer...\n", *(int*)arg);
    sem_wait(&printerSem);
    // printing
    printf("%d is printing.....\n", *(int*)arg);
    sleep(1 + rand() % 4);
    printf("%d finished!\n", *(int*)arg);
    sem_post(&printerSem);
    free(arg);
}

int main(){
    srand(time(NULL));
    sem_init(&printerSem, 0, 2);
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        int* num = malloc(sizeof(int));
        *num = i;
        if(pthread_create(th + i, NULL, printer, num)){
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
    sem_destroy(&printerSem);
    return EXIT_SUCCESS;
}