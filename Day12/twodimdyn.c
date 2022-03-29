#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int** dynarray = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        *(dynarray + i) = malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            *(*(dynarray + i) + j) = 10;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", *(*(dynarray + i) + j));
        }
        putchar('\n');
    }

    for(int i = 0; i < n; i++){
        free(*(dynarray + i));
    }
    free(dynarray);
    return 0;
}