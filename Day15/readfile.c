#include <stdio.h>

int main(){
    FILE *fr = fopen("myfile.txt", "r");
    int ch;
    while ((ch = fgetc(fr)) != EOF){
        putchar(ch);
        fseek(fr, 1, SEEK_CUR);
    }
    /*fseek(fr, 1, SEEK_SET);
    while ((ch = fgetc(fr)) != EOF){
        putchar(ch);
    }
    fseek(fr, 2, SEEK_SET);
    while ((ch = fgetc(fr)) != EOF){
        putchar(ch);
    }*/
    fclose(fr);
    return 0;
}