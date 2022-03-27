#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define NAMELEN 3
#define COUNT 10

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int randInt(int min, int max){
    return min + rand() % (max -min + 1); // [min; max]
}


typedef struct {
    char name[NAMELEN];
    double x;
    double y;
} point;

double distance(point,point);

int main(){
    srand(time(NULL));
    point points[COUNT];
    for (int i = 0; i < COUNT; i++){
        points[i].x = randDouble(0, 5);
        points[i].y = randDouble(0, 5);
        points[i].name[0] = randInt('A', 'Z');
        for (int j = 1; j < NAMELEN; j++){
            points[i].name[j] = randInt('a', 'z');
        }
        points[i].name[NAMELEN] = '\0';
    }

    for (int i = 0; i < COUNT; i++){
        printf("%s (%.1lf, %.1lf)\n", points[i].name, points[i].x, points[i].y);
    }

    /*for (int i = 0; i < COUNT; i++){
        for (int j = 0; j < COUNT; j++){
            [i], [j]
        }
    }*/

    return 0;
}

double distance(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
