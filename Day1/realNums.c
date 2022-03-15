#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
   double num1, num2, result;
   scanf("%lf %lf", &num1, &num2);
   result = sqrt(num1 + num2);
   printf("%.2lf\n", result);
   return EXIT_SUCCESS;
}
