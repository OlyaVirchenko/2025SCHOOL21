#include <stdio.h>
#include <math.h>

int main() {
    float x;
    int scan = (scanf("%f", &x));
    if (scan != 1 || x == 0) {
       printf("n/a\n"); 
    } else {
        double y = 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1.0/3) - 1e3) * x + 3) / (x * x / 2) - x * pow((10 + x), (2/x)) - 1.01;
        printf("%.1lf\n", y);
    }
}