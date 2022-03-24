#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    double width;
    double height;
} rectangle;

#define EPS 0.001
int compRects(const void* r1, const void* r2){
    rectangle* rect1 = (rectange*)r1;
    rectangle* rect2 = (rectange*)r2;
    double s1 = rect1->width * rect1->height;
    double s2 = rect2->width * rect2->height;
    if (fabs(s1 - s2) < EPS){
        return 0;
    } else if (s1 > s2){
        return -1;
    }
    return 1;
}


typedef struct {
    char name[100];
    int number;
    double grade;
} student;

void printInfo(student);

#define COUNT 10

int compare2(const void* st1, const void* st2){
    student* s1 = (student*)st1;
    student* s2 = (student*)st2;
    if (strcmp(s2->name, s1->name) == 0 && s2->number == s1->number){
        return 0;
    }
    return 1;
}

int compare1(const void* st1, const void* st2){
    student* s1 = (student*)st1;
    student* s2 = (student*)st2;
    return strcmp(s1->name, s2->name);
}



int main(){
    srand(time(NULL));
    const char names[][10] = { "Ivan", "Zoro", "Miro", "Nadq", "Pesho" };
    student stds[COUNT];
    for (int i = 0; i < COUNT; i++){
        strcpy(stds[i].name, names[rand() % 5]);
        stds[i].number = rand() % 100;
        stds[i].grade = rand() % 100;
    }
    qsort(stds, COUNT, sizeof(student), compare1);
    for (int i = 0; i < COUNT; i++){
        printInfo(stds[i]);
    }

    student forSearch;
    forSearch.grade = 4.40;
    strcpy(forSearch.name, "Nadq");
    forSearch.number = 20;

    student *st = bsearch(&forSearch, stds, COUNT, sizeof(student), compare2);
    if (st == NULL){
        printf("Not found!\n");
    } else {
        printf("\n\nFound:\n");
        printInfo(*st);
    }
    return 0;
}

void printInfo(student st){
    printf("Name: %s, ", st.name);
    printf("Number: %d, ", st.number);
    printf("Grade: %.2lf\n", st.grade);
}