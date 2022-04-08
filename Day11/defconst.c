#include <stdio.h>

#define NUM 1

int main(){
    #if NUM == 1
        #warning Nqkakuv warining 
    #endif
    #if NUM == 10
        #error Nqkakva greshka
    #endif

    printf("%s\n", __FILE__);
    printf("%s\n", __TIME__);
    printf("%s\n", __TIMESTAMP__);



    #line 4 

    printf("Line number: %d\n", __LINE__);
}