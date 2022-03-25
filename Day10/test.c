#include <stdio.h>
#include <math.h>

void printValue1(double num){
    printf("Num = %.1lf\n", num);
}

void printValue2(double num){
    printf("Value = %.2lf\n", num);
}

typedef double liters;

typedef void(*functionPtr)(double);

/*
void (*getFunc(int a))(double){
    if (a == 1){
        return printValue1;
    } else {
        return printValue2;
    }
}
*/
functionPtr getFunc(int a){
    if (a == 1){
        return printValue1;
    } else {
        return printValue2;
    }
}

/*void callfunc(int n,  void (*fp)(double)) {
    if (n == 1){
        fp(4.5);
    } else {
        fp(-4.5);
    }
}*/

void callfunc(int n, functionPtr fp) {
    if (n == 1){
        fp(4.5);
    } else {
        fp(-4.5);
    }
}


/*struct point {
    double x;
    double y;
};
typedef struct point point;*/

typedef struct {
    double x;
    double y;
} point;

double distance(point,point);

int main(){
    /*point pts[2]; //= { {.x=10, .y=20 }, { .x=0, .y=29.5} };
    //pts[0].x = 20;
    point p1 = { .x = 20, .y = 0 };
    point p2 = { .x = 20, .y = 0 };
    pts[0] = p1;
    pts[1] = p2;
    pts[0].x = 20;
    printf("Distance: %.2lf\n", distance(pts[0], pts[1]));*/
    return 0;
}

double distance(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
