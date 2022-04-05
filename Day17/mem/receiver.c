#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MEMSIZE 1024

int main(int argc, char **argv){
    // ftok to generate unique key
    key_t key = ftok("aaaa",65);
    // shmget returns an identifier in shmid
    int shmid = shmget(key, MEMSIZE, 0666 | IPC_CREAT);
    // shmat to attach to shared memory
    char *str = shmat(shmid, NULL, 0);
    printf("Data read from memory: %s\n", str);
    //detach from shared memory 
    shmdt(str);
    // destroy the shared memory
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}