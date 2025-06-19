/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *sum);
int sum_numbers(int *buffer, int length);
void find_numbers(int *buffer, int length, int *sum_n);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/

int main() {
    int length, buffer[NMAX];
    if (input(buffer, &length) != 0) {
        printf("n/a");
    } else {
        int sum_n = sum_numbers(buffer, length);
        output(&sum_n);
        find_numbers(buffer, length, &sum_n);
    }

    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
void find_numbers(int *buffer, int length, int *sum_n) {
    int special[NMAX], count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && *sum_n % buffer[i] == 0) {
            special[count++] = buffer[i];
        }
    }

    // Вывод специальных элементов
    for (int i = 0; i < count; i++) {
        printf("%d%c", special[i], (i < count - 1) ? ' ' : '\n');
    }
}

int input(int *buffer, int *length) {
    char ch;
    if (scanf("%d%c", length, &ch) != 2 || *length > NMAX || *length < 1 || (ch != ' ' && ch != '\n')) {
        // printf("n/a");
        return -1;
    }

    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d%c", p, &ch) != 2 || (ch != ' ' && ch != '\n')) {
            // printf("n/a");
            return -2;
        }
    }

    if (ch != '\n') {
        // printf("n/a");
        return -2;
    }
    return 0;
}

void output(int *sum) { printf("%d\n", *sum); }
