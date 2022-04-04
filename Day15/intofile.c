#include <stdio.h>

int main(){
    FILE* fp = fopen("myfile.txt", "r");
    char buffer[200];
    while (fgets(buffer, 200, fp) != NULL){
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}