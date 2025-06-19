#include <stdio.h>

int fib(int x);

int main() {
    int x;
    char some;
    int scan = scanf("%d%c", &x, &some);

    if (scan == 2 && some == '\n') {
        printf("%d\n", fib(x));
    } else {
        printf("n/a\n");
    }
    return 0;
}

int fib(int x) {
    if (x == 2 || x == 1) return 1;
    return fib(x - 1) + fib(x - 2);
}
