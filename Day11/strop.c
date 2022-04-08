#include <stdio.h>

// stringize operator #
#define PRINTVAR(num) printf("%s = %d\n", #num, num)
#define  message_for(a,b)  printf(#a " and " #b ": We love you!\n")


// token pasting operator ##
#define PRINTNUMN(n) printf("%d\n", num##n)
#define PRINTVARN(var,n) printf("%d\n", var##n)

int main(){
    int a = 20, number = 600;
    PRINTVAR(a);  // a = 20
    PRINTVAR(number);
    message_for(Zevs, Kleopatra);
    int num1 = 30, num2 = 25, num3 = 1050;
    //PRINTNUMN(2);
    PRINTVARN(num, 1);
    PRINTVARN(num, 3);
    return 0;
}