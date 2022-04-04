#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main(void) {
   DIR *dr;
   struct dirent *en;
   dr = opendir(".");
   if (dr == NULL) {
       perror("error:");
       return EXIT_FAILURE;
   }
   while ((en = readdir(dr)) != NULL) {
         printf("%s\n", en->d_name);
   }
   closedir(dr);
   return EXIT_SUCCESS;
}