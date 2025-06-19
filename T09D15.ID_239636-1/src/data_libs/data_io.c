#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

void input(double **data, int *n) {
    scanf("%d", n);

    *data = (double *)calloc(*n, sizeof(double));

    for (int i = 0; i < *n; i++) {
        if (scanf("%lf", &(*data)[i]) != 1) {
            free(data);
        }
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}
