#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int input_modes(int *n);
int input(int *rows, int *cols);
void output(int *rows, int *cols, int ***matr);
void output_static(int (*matr1)[MAX], int *rows, int *cols);
void arr_static(int (*matr1)[MAX], int *cols, int *rows);
void arr_dyn1(int *rows, int *cols, int ***matr);
void arr_dyn2(int *rows, int *cols, int ***matr);
void arr_dyn3(int *rows, int *cols, int ***matr);

int main() {
    int n;
    int **matr;
    int rows, cols;
    int matr1[MAX][MAX];

    int o = input_modes(&n);
    int inpres = (input(&rows, &cols));
    if (inpres == -1) {
        printf("n/a");
    }
    if (o == -1) {
        printf("n/a");
    } else if (o == 1) {
        arr_static(matr1, &cols, &rows);
        output_static(matr1, &rows, &cols);
    } else if (o == 2) {
        arr_dyn1(&rows, &cols, &matr);
        output(&rows, &cols, &matr);
        for (int i = 0; i < rows; i++) {
            free(matr[i]);
        }
        free(matr);
    } else if (o == 3) {
        arr_dyn2(&rows, &cols, &matr);
        output(&rows, &cols, &matr);
        free(matr);
    } else if (o == 4) {
        arr_dyn3(&rows, &cols, &matr);
        output(&rows, &cols, &matr);
        free(matr);
    }

    return 0;
}

int input(int *rows, int *cols) {
    char ch;
    // int mode = scanf("%d%c", n, &ch);
    if (scanf("%d%d%c", rows, cols, &ch) != 3 || (ch != ' ' && ch != '\n')) {
        // printf("n/a");
        return -1;
    }
    return 0;
}

int input_modes(int *n) {
    char ch;
    // int mode = scanf("%d%c", n, &ch);
    if (scanf("%d%c", n, &ch) != 2 || (ch != ' ' && ch != '\n')) {
        // printf("n/a");
        return -1;
    }

    if (*n == 1) {
        return 1;
    } else if (*n == 2) {
        return 2;
    } else if (*n == 3) {
        return 3;
    } else if (*n == 4) {
        return 4;
    } else {
        return -1;
    }
    return 0;
}

// Array of pointers to array
void arr_dyn1(int *rows, int *cols, int ***matr) {
    // Выделяем память под столбцы и строки
    *matr = (int **)malloc(*rows * sizeof(int *));
    // if (matr == NULL)
    for (int i = 0; i < *rows; i++) {
        (*matr)[i] = (int *)malloc(*cols * sizeof(int));
    }

    // Записываем матрицу в выделенную память
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &(*matr)[i][j]);
        }
    }
}

// Array of pointers to array segments within one buffer
void arr_dyn2(int *rows, int *cols, int ***matr) {
    *matr = malloc(*rows * *cols * sizeof(int *) + *rows * sizeof(int *));  // выделяем память под ее копию
    int *ptr = (int *)(*matr + *rows);  // указатель на начало строки данных
    for (int i = 0; i < *rows; i++) {
        (*matr)[i] = ptr + *cols * i;
    }

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &(*matr)[i][j]);
        }
    }
}

// Array of pointers to segments of the second array
void arr_dyn3(int *rows, int *cols, int ***matr) {
    *matr = malloc(*rows * sizeof(int *));
    int *values_array = malloc(*rows * *cols * sizeof(int));

    for (int i = 0; i < *rows; i++) {
        (*matr)[i] = values_array + *cols * i;
    }

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &(*matr)[i][j]);
        }
    }
    free(values_array);
}

void arr_static(int (*matr1)[MAX], int *cols, int *rows) {
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &matr1[i][j]);
        }
    }
}

void output_static(int (*matr1)[MAX], int *rows, int *cols) {
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            if (j == 0) {
                printf("%d", matr1[i][j]);
            } else {
                printf(" %d", matr1[i][j]);
            }
        }
        printf("\n");
    }
}

void output(int *rows, int *cols, int ***matr) {
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            if (j == 0) {
                printf("%d", (*matr)[i][j]);
            } else {
                printf(" %d", (*matr)[i][j]);
            }
        }
        printf("\n");
    }
}