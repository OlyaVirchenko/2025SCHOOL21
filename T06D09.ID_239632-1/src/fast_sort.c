#include <stdio.h>

#define MASS 10
int input(int *a);
void quick_sort(int *a, int first, int last);
void swap(int *a, int *b);
void output(int *a, int *b);
void heapify(int *a, int n, int i);
void heap_sort(int *a, int n);
void copy(int *a, int *b);

int main() {
    int data[MASS];
    int data2[MASS];

    int inpres = input(data);
    if (inpres == -1 || inpres == -2) {
        printf("n/a");
    } else {
        copy(data, data2);
        quick_sort(data, 0, 9);
        heap_sort(data2, 10);
        output(data, data2);
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

void output(int *a, int *b) {
    for (int *p = a; p - a < 10; p++) {
        if (p == a) {
            printf("%d", *p);
        } else {
            printf(" %d", *p);
        }
    }

    for (int *p = b; p - b < 10; p++) {
        if (p == b) {
            printf("\n%d", *p);
        } else {
            printf(" %d", *p);
        }
    }
}

void quick_sort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle) left++;
            while (a[right] > middle) right--;
            if (left <= right) {
                swap(a + left, a + right);
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}

void heapify(int *a, int n, int i) {
    int largest = i;        // корень
    int left = 2 * i + 1;   // левый потомок
    int right = 2 * i + 2;  // правый потомок

    // если левый больше корня
    if (left < n && a[left] > a[largest]) largest = left;

    // если правый больше текущего наибольшего
    if (right < n && a[right] > a[largest]) largest = right;

    // если наибольший не корень — меняем местами и продолжаем
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heap_sort(int *a, int n) {
    // строим кучу (heap)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // извлекаем элементы из кучи один за другим
    for (int i = n - 1; i > 0; i--) {
        // перемещаем текущий корень в конец
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // вызываем heapify для уменьшенной кучи
        heapify(a, i, 0);
    }
}

void copy(int *a, int *b) {
    for (int i = 0; i < MASS; i++) {
        *(b + i) = *(a + i);
    }
}
