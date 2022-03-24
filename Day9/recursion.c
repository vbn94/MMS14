#include <stdio.h>

void func(int n){
    if (n == 0){
        return;
    }
    printf("Hello\n");
    func(n - 1);
}

unsigned factorial(unsigned n){
    if (n == 0){
        return 1;
    }
    return factorial(n - 1) * n;
}

void counter(int num){
    if (num == 0){
        return;
    }
    printf("Counter: %d\n", num);
    counter(num - 1);
    printf("Counter: %d\n", num);
}

double power(double num, int pow){
    if (pow == 0){
        return 1;
    } else if (pow < 0){
        return 1 / power(num, -pow);
    }
    return num * power(num, pow - 1);
}


int main(){
    printf("%.2lf\n", power(2, -2));
    return 0;
}