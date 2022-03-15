#include <stdio.h>
#include <stdlib.h>

int main(){
    double num1, num2;
    char op;
    scanf("%lf %c %lf", &num1, &op, &num2);
    if (op == '+'){
        printf("%.2lf\n", num1 + num2);
    } else if (op == '-'){
        printf("%.2lf\n", num1 - num2);
    } else if (op == 'x'){
        printf("%.2lf\n", num1 * num2);
    } else if (op == '/'){
        if (num2 == 0){
            fprintf(stderr, "Zero divide error!\n");
            return EXIT_FAILURE;
        }
        printf("%.2lf\n", num1 / num2);
    } else {
        fprintf(stderr, "Invalid operation!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}