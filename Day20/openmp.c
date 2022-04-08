#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <omp.h>

int main(){

    /*
    int sum = 0;
    int a[] = {10, 20, 30, 40, 50};
    int b[] = {2, 3, 4, 5, 6};
    int c[5];

    #pragma omp parallel for
    for (int i = 0; i < 5; i++){
        c[i] = a[i] + b[i];
    }

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 5; i++){
        sum += a[i];
    }
    printf("Sum = %d\n", sum);
    for (int i = 0; i < 5; i++){
        printf("%d ", c[i]);
    }
    putchar('\n');*/
    int i = 0;
    omp_lock_t l;
    omp_init_lock(&l);
    #pragma omp parallel num_threads(200)
    {
        for (int j = 0; j < 100; j++){
            //omp_set_lock(&l);
           #pragma omp critical
            i++;
            //omp_unset_lock(&l);
        }
    }
    omp_destroy_lock(&l);
    printf("i = %d\n", i);
    return EXIT_SUCCESS;
}