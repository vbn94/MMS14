#include <stdio.h>

int main(){
    FILE* fp = fopen("myfile.txt", "w");
    char buffer[200];
    int cnt = 0;
    while (fgets(buffer, 200, stdin) != NULL){
        fputs(buffer, fp);
        cnt++;
    }
    fclose(fp);
    printf("Counter = %d\n", cnt);
    return 0;
}