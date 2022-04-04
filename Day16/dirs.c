#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
   /*DIR *dr;
   struct dirent *en;
   dr = opendir("/home/vnachev/MMS14/Day16");
   if (dr == NULL) {
       perror("error:");
       return EXIT_FAILURE;
   }
   while ((en = readdir(dr)) != NULL) {
       if (en->d_type == DT_DIR && en->d_name[0] != '.'){
         printf("%s\n", en->d_name);
       }
   }
   closedir(dr);*/
   /*if(mkdir("mydir", 0777) == 0){
       printf("Created...\n");
   } else {
       perror("error info:");
       return EXIT_FAILURE;
   }*/

   if(rmdir("mydir") == 0){
       printf("Deleted...\n");
   } else {
       perror("error info:");
       return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}