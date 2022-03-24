#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdint.h>

#define OPT_U 1
#define OPT_A 2

void setBit(uint8_t* mask, size_t bit){
    *mask |= (1 << bit);
}

int checkBit(uint8_t mask, size_t bit){
    return !!(mask & (1 << bit));
}

int main(int argc, char *argv[]){
    int opt;
    char username[100];
    int age;
    uint8_t flag = 0;
    while ((opt = getopt(argc, argv, "u:a:")) != -1){
        switch (opt){
            case 'u':
                strcpy(username, optarg);
                setBit(&flag, OPT_U);
                break;
            case 'a':
                sscanf(optarg, "%d", &age);
                setBit(&flag, OPT_A);
                break;
        }
    }

    if (checkBit(flag, OPT_U)){
        printf("Username: %s\n", username);
    }
    if (checkBit(flag, OPT_A)){
        printf("Age: %d\n", age);
    }
    return 0;
}