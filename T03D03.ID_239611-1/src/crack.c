#include <stdio.h>
#include <math.h>

int main() {

    float x, y;

    int scan = scanf("%f%f", &x, &y);

    if (scan != 2) {
        printf("n/a\n");
    } else if (x * x + y * y < 25) {
        printf("GOTCHA\n");
    } else {
        printf("MISS\n");
    }


    return 0;
}