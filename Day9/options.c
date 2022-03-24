#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[]){
    int opt;
    int flagA = 0;
    while ((opt = getopt(argc, argv, ":abz")) != -1){
        switch (opt){
            case 'a':
                if (!flagA){
                    printf("Option a is set!\n");
                    flagA = 1;
                } else {
                    printf("Option a already exits!\n");
                }
                break;
            case 'b':
                printf("Option b is set!\n");
                break;
            case 'z':
                printf("Option z is set!\n");
                break;
            case '?':
                printf("%c No such option!\n", optopt);
                break;  
        }
    }
    return 0;
}