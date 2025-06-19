#include "s21_string.h"

#include <stdio.h>

void tests_strlen(const char *input, size_t expected) {
    size_t res = s21_strlen(input);
    // Вход
    printf("INPUT: \"%s\"\n", input);

    // Выход
    printf("OUTPUT: %zu\n", res);

    // Результат
    if (expected == res) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

void tests_strcmp(const char *a, const char *b, int expect) {
    // Вход
    printf("INPUT: \"%s\" \"%s\"\n", a, b);

    // Выход
    printf("OUTPUT: %d\n", expect);

    // Результат
    if (expect) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

void tests_stcpy(char *destination, const char *source, char *expect) {
    char *result = s21_strcpy(destination, source);
    // Вход
    printf("INPUT: \"%s\"\n", source);

    printf("EXPECTED: \"%s\"\n", destination);
    // Выход
    printf("OUTPUT: \"%s\"\n", result);

    // Результат
    if (s21_strcmp(expect, result) == 0) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

void s21_strlen_test() {
    tests_strlen("Hello AI!", 9);
    tests_strlen("Unforeseen\0circumstances", 10);
    tests_strlen("", 0);
    tests_strlen(" ", 1);
}

void s21_strcmp_test() {
    tests_strcmp("Hello", "Hello", 0);
    tests_strcmp("Hello, AI", "Hello, World", 1);
    tests_strcmp("Hello, World", "Hello, AI", -1);
    tests_strcmp("abc", "bcd", -1);
    tests_strcmp("bc", "abc", 1);
}

void s21_strcpy_test() {
    char destination[100];
    tests_stcpy(destination, "Hello", "Hello");
    tests_stcpy(destination, "Hello,\0 world!", "Hello,");
    tests_stcpy(destination, "", "");
}

int main() {
#ifdef STRLEN_TEST
    s21_strlen_test();
#endif

#ifdef STRCMP_TEST
    s21_strcmp_test();
#endif

#ifdef STRCPY_TEST
    s21_strcpy_test();
#endif

    return 0;
}