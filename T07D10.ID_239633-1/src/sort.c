#include <stdio.h>
#include <stdlib.h>

int *input(int *n);
void bubbleSort(int *arr, int n);
void output(int *arr, int n);

int main() {
    int n;
    int *arr = input(&n);
    if (arr == NULL) {
        printf("n/a");
    } else {
        bubbleSort(arr, n);
        output(arr, n);
    }
    free(arr);
    return 0;
}

int *input(int *n) {
    // scanf("%d", n);

    if (scanf("%d", n) != 1 || *n <= 0) {
        // printf("n/a");
        return NULL;
    }

    int *arr = (int *)calloc(*n, sizeof(int));
    if (arr == NULL) {
        // printf("n/a");
        return NULL;
    }

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            // printf("n/a");
            return NULL;
        }
    }
    return arr;
}

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}
