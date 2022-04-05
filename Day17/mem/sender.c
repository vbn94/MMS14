#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define MEMSIZE 1024

int main(int argc, char **argv){
    // ftok to generate unique key
    key_t key = ftok("aaaa",65);
  
    // shmget returns an identifier in shmid
    int shmid = shmget(key, MEMSIZE, 0666 | IPC_CREAT);

    // shmat to attach to shared memory
    char *str = shmat(shmid, NULL, 0);
    printf("Write Data : ");
    fgets(str, MEMSIZE, stdin);
    printf("Data written in memory: %s\n",str);
    //detach from shared memory 
    shmdt(str); 
    return 0;
}