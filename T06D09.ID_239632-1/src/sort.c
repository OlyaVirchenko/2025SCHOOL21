#include <stdio.h>

#define MASS 10
int input(int *a);
void swap(int *a, int *b);
int bubble_sort(int *a);
void output(int *a);

int main() {
    int data[MASS];

    int inpres = input(data);
    if (inpres == -1 || inpres == -2) {
        printf("n/a");
    } else {
        bubble_sort(data);
        output(data);
    }

    return 0;
}

int input(int *a) {
    char ch;
    for (int *p = a; p - a < 10; p++) {
        if (scanf("%d%c", p, &ch) != 2 || (ch != ' ' && ch != '\n')) {
            // printf("n/a");
            return -1;
        }
    }
    return 0;
}

void swap(int *a, int *b) {
    int num = *a;
    *a = *b;
    *b = num;
}

int bubble_sort(int *a) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a + j, a + j + 1);
            }
        }
    }
    return 0;
}

void output(int *a) {
    for (int *p = a; p - a < 10; p++) {
        if (p == a) {
            printf("%d", *p);
        } else {
            printf(" %d", *p);
        }
    }
}
