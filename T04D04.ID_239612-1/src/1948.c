#include <math.h>
#include <stdio.h>

int find_quotient(int a, int b);
int rem(int a, int b);
int is_prime(int a);
int max_prime_del(int a);

int main() {
    int a;
    char some;
    int scan = scanf("%d%c", &a, &some);

    if (a < 0) {
        a = -a;
    }
    if (a == 1 || a == 2) {
        printf("%d", a);
    }

    int res = max_prime_del(a);

    if (scan == 2 && some == '\n') {
        printf("%d\n", res);
    } else {
        printf("n/a\n");
    }
    return 0;
}

int find_quotient(int a, int b) {
    int q = 0;
    while (b <= a) {
        a = a - b;
        q++;
    }
    return q;
}

int rem(int a, int b) {
    int q = find_quotient(a, b);
    return a - b * q;
}

int is_prime(int a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (rem(a, i) == 0) {
            return 1;
        }
    }
    return 0;
}

int max_prime_del(int a) {
    int max_del = 1;
    for (int i = 2; i <= a; i++) {
        if (rem(a, i) == 0 && is_prime(i) == 0) {
            max_del = i;
        }
    }
    return max_del;
}
