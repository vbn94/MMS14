#include <stdio.h>
#include <stdlib.h>
int main(){
   int num1, num2, result;
   printf("Enter number 1: ");
   scanf("%d", &num1);
   printf("Enter number 2: ");
   scanf("%d", &num2);
   result = num1 + num2;
   printf("Result = %d\n", result);
   return EXIT_SUCCESS;
}
