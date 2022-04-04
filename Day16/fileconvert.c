#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char **argv){
    if (argc != 4){
        fprintf(stderr, "Invalid arguments!\n");
        return EXIT_FAILURE;
    }
    if (!strcmp(argv[3], "-BT")){
        FILE* srcfile = fopen(argv[1], "rb");
        if (NULL == srcfile){
            perror("error");
            return EXIT_FAILURE;
        }
        FILE* destfile = fopen(argv[2], "w");
        if (NULL == destfile){
            perror("error");
            return EXIT_FAILURE;
        }
        uint16_t num;
        while (fread(&num, sizeof(num), 1, srcfile)){
            fprintf(destfile, "%hd\n", num);
        }
        fclose(destfile);
        fclose(srcfile);
    } else if (!strcmp(argv[3], "-TB")){
        FILE* srcfile = fopen(argv[1], "r");
        if (NULL == srcfile){
            perror("error");
            return EXIT_FAILURE;
        }
        FILE* destfile = fopen(argv[2], "wb");
        if (NULL == destfile){
            perror("error");
            return EXIT_FAILURE;
        }
        uint16_t num;
        while (fscanf(srcfile, "%hd", &num) != EOF){
            fwrite(&num, sizeof(num), 1, destfile);
        }
        fclose(destfile);
        fclose(srcfile);
    } else {
        fprintf(stderr, "Invalid mode!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}