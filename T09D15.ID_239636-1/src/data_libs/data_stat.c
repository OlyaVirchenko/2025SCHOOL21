#include "data_stat.h"

double max(double *data, int n) {
    double max = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

double min(double *data, int n) {
    double min = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

double mean(double *data, int n) {
    double sum = 0;
    for (double *p = data; p - data < n; p++) {
        sum = sum + *p;
    }
    return sum / n;
}

double variance(double *data, int n) {
    double m = mean(data, n);
    double sum_m = 0;
    for (double *p = data; p - data < n; p++) {
        sum_m += (*p - m) * (*p - m);
    }
    return sum_m / n;
}
