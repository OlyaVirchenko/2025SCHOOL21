#include <stdio.h>

int main() {
    int a, b;
    char some;
    int in = (scanf("%d%d%c", &a, &b, &some));
    if (in == 3 && some == '\n') {
        if (b == 0) {
            printf("%d %d %d n/a\n", a + b, a - b, a * b);
            return 0;
        } else {
            printf("%d %d %d %d\n", a + b, a - b, a * b, a / b);
            return 0;
        }
    } else {
        printf("n/a\n");
    }
}
