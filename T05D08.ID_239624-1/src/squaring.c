#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];

    int inpres = input(data, &n);
    if (inpres == -1 || inpres == -2) {
        return 0;
    }

    squaring(data, n);

    output(data, n);

    return 0;
}

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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p == a) {
            printf("%d", *p);
        } else {
            printf(" %d", *p);
        }
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = *p * *p;
    }
}
