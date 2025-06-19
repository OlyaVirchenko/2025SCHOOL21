#include "s21_string.h"

#include <stdio.h>

int s21_strlen(const char *s) {
    int count = 0;
    while (*s != '\0') {
        s++;
        count++;
    }
    return count;
}

int s21_strcmp(const char *a, const char *b) {
    while (*a == *b && *a != '\0') {
        a++;
        b++;
    }

    if (*a == '\0' && *b == '\0') {
        return 0;
    }

    if (*a > *b) {
        return 1;
    } else {
        return -1;
    }
    return 0;
}

char *s21_strcpy(char *destination, const char *source) {
    char *current = destination;

    // проходим по массиву до тех пор, пока не встретим '\0'
    while (*source != '\0') {
        // копируем символ
        *current = *source;

        // сдвигаем указатели на одну ячейку вперед
        source++;
        current++;
    }
    // указываем конец строки
    *current = '\0';

    // вернуть указатель на скопированную строку
    return destination;
}