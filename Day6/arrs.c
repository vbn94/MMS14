#include <stdio.h>
#include <string.h>

int sum(int* arr, int len){
    int n = sizeof(arr) / sizeof(arr[0]); // not working
}

int main(){

    /*char* str1 = "1234567890";
    char str2[20];

    strncpy(str2, str1, 5);

    printf("String1: %s\n", str1);
    printf("String2: %s\n", str2);*/

    char name[100];
    char lastname[100];
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = '\0';
    printf("Your name is %s\n", name);
    /*int arr[] = {10, 20, 30, 50, 90};
    int n = sizeof(arr) / sizeof(arr[0]);  // count elements*/

    /*char str[] = "Hello";
    char str2[] = "MMS";
    strcpy(str, str2);
    printf("%lu\n", strlen(str + 2));*/

    /*str[7] = '\0';
    char str2[] = {'M', 'M', 'S', 0};
    //printf("%s\n", str);
    printf("%s\n", str);*/
   /* int i = 0;
    while (*(str + i)){
        putchar(*(str + i));
        i++;
    }
    putchar('\n');*/
    double num = 20.15;
    char output[100];
    sprintf(output, "Num = %.2lf", num);
    printf("%s", output);
    return 0;
}