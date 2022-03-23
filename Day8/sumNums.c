#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc == 1){
        fprintf(stderr, "Arguments error!\n");
        return 1;
    }
    int sum = 0;
    for (int i = 1; i < argc; i++){
        int num;
        sscanf(argv[i], "%d", &num); // atoi(argv[i])
        sum += num;
    }
    printf("Sum = %d\n", sum);
    return 0;
}