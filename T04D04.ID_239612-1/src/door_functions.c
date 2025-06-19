#include <math.h>
#include <stdio.h>

double agnesi(double x);
double bernoulli(double x);
double hyperbola(double x);

int main() {
    double step = (M_PI + M_PI) / 41;

    for (double i = -M_PI; i <= M_PI; i += step) {
        double column1 = agnesi(i);
        double column2 = bernoulli(i);
        double column3 = hyperbola(i);
        if (isnan(column2)) {
            printf("%.7f | %.7lf | - | %.7lf\n", step, column1, column3);
        } else {
            printf("%.7f | %.7lf | %.7lf | %.7lf\n", step, column1, column2, column3);
        }
    }

    return 0;
}

double agnesi(double x) {
    double res = 1 / (1 + x * x);
    return res;
}

double bernoulli(double x) {
    double res = sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
    return res;
}

double hyperbola(double x) {
    double res = 1 / (x * x);
    return res;
}