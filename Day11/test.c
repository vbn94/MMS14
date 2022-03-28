#include <stdio.h>

#define NUM 42
#define myint int
#define ako if
#define SUM(x,y) ((x) + (y))
#define MULT(a,b) ((a)*(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(num1,num2) ((num1)<(num2)?(num1):(num2))
#define FORI(start,end,step) for(int i = start; i <= end; i+=step)
#define MAX3(a,b,c) MAX(MAX(a,b),c)
#define DECLAREVAR(type,name,init) type name = init
#define PI 3.141592
#define CIRCLEAREA(r) (PI*(r)*(r))

#define SWAPVARS(a,b,type) {type temp=a; \
                                   a=b;   \
                                  b=temp; }

#define PRINTVAL(x) printf("%d\n", x)

int main(){
    int a1 = 20, b1 = 30;
    SWAPVARS(a1, b1, int);
    DECLAREVAR(int,number,30);
    PRINTVAL(a1);
    PRINTVAL(b1);
    int a = SUM(5,3) * 2;
    int b = MULT(3 + 1, 5);
    int c = MAX3(10, 5, 60);
    if (1){
        printf("a = %d, b = %d, c = %d\n",a, b, c);
    }
    FORI(0, 20, 2){
        printf("%d ", i);
    }
    putchar('\n');
    return 0;
}