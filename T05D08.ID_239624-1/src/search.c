/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
// void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int n, double *m, double *var);

int main() {
    int n, data[NMAX];

    int inpres = input(data, &n);
    if (inpres == -1 || inpres == -2) {
        return 0;
    }
    double min = mean(data, n);
    double var = variance(data, n);

    // mean(data, n);
    // variance(data, n);
    search(data, n, &min, &var);

    return 0;
}

// input
int input(int *a, int *n) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || *n > NMAX || *n < 1 || (ch != ' ' && ch != '\n')) {
        printf("n/a");
        return -1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &ch) != 2 || (ch != ' ' && ch != '\n')) {
            printf("n/a");
            return -2;
        }
    }
    if (ch != '\n') {
        printf("n/a");
        return -2;
    }
    return 0;
}

// mean
double mean(int *a, int n) {
    double sum = 0;
    for (int *p = a; p - a < n; p++) {
        sum = sum + *p;
    }
    return sum / n;
}

// variance
double variance(int *a, int n) {
    double m = mean(a, n);
    double sum_m = 0;
    for (int *p = a; p - a < n; p++) {
        sum_m += (*p - m) * (*p - m);
    }
    return sum_m / n;
}

int sigma(int *p, double *m, double *var) {
    double sigma = sqrt(*var);
    if (*p >= *m - 3 * sigma && *p <= *m + 3 * sigma) {
        return 1;
    }
    return 0;
}

int search(int *a, int n, double *m, double *var) {
    for (int *p = a; p - a < n; p++) {
        int sg = sigma(p, m, var);
        if ((*p % 2) == 0 && *p >= *m && *p != 0 && sg == 1) {
            printf("%d", *p);
            return 0;
        }
    }
    printf("%d", 0);
    return 0;
}
