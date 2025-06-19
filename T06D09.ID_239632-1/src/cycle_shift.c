#include <stdio.h>
#define NMAX 10

int input(int *data, int *n, int *number);

void output(int *data);
void cycle_shift(int *data, int n, int number);

int main() {
    int data[NMAX], n, number;

    int inpres = input(data, &n, &number);
    if (inpres == -1 || inpres == -2) {
        printf("n/a");
    } else {
        cycle_shift(data, n, number);
        output(data);
    }

    return 0;
}

int input(int *data, int *n, int *number) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || *n > NMAX || *n < 1 || (ch != ' ' && ch != '\n')) {
        // printf("n/a");
        return -1;
    }

    for (int *p = data; p - data < *n; p++) {
        if (scanf("%d%c", p, &ch) != 2 || (ch != ' ' && ch != '\n')) {
            // printf("n/a");
            return -2;
        }
    }

    if (scanf("%d%c", number, &ch) != 2 || *number > NMAX || *number < 1 || (ch != ' ' && ch != '\n')) {
        // printf("n/a");
        return -1;
    }

    if (ch != '\n') {
        // printf("n/a");
        return -2;
    }
    return 0;
}

// Функция переворота
void reverse(int *data, int start, int end) {
    while (start < end) {
        int temp = data[start];
        data[start] = data[end];
        data[end] = temp;
        start++;
        end--;
    }
}

// Функция для циклического сдвига массива
void cycle_shift(int *data, int n, int number) {
    number = number % n;
    if (number < 0) {
        number = n + number;
    }

    reverse(data, 0, number - 1);
    reverse(data, number, n - 1);
    reverse(data, 0, n - 1);
}

void output(int *data) {
    for (int *p = data; p - data < 10; p++) {
        if (p == data) {
            printf("%d", *p);
        } else {
            printf(" %d", *p);
        }
    }
}
