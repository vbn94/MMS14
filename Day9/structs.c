#include <stdio.h>
#include <string.h>


typedef int numbertype;
//typedef unsigned int liters;

typedef struct {
    double x;
    double y;
} point;

//typedef struct point point;
//typedef struct student student;

typedef struct  {
    char name[100];
    int number;
    double grade;
} student;


int main(){
    point pointA, pointB;
    pointA.x = 20.4;
    pointA.y = 18.2;
    pointB.x = 10;
    pointB.y = 0;
    printf("Point A(%.1lf, %.1lf)\n", pointA.x, pointA.y);
    printf("Point B(%.1lf, %.1lf)\n", pointB.x, pointB.y);
   // printf("Size of struct: %lu\n", sizeof(struct point));

   student st1;
   strcpy(st1.name, "Pesho");
   st1.grade = 5.50;
   st1.number = 101;

   numbertype num = 20;
   return 0;
}