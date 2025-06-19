#include <stdio.h>

int max(int a, int b);

int main() {
    int a, b;
    char some;
    int in = (scanf("%d%d%c", &a, &b, &some));
    if (in == 3 && some == '\n') {
        int res = max(a, b);
        printf("%d\n", res);
    } else {
        printf("n/a\n");
    }
}

int max(int a, int b) {
    if (a <= b) {
        return b;
    } else {
        return a;
    }
}
