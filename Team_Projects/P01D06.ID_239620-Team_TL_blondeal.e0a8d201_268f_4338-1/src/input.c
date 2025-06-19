#include <stdio.h>

#include "pong.h"

char input() {
    char ch = getchar();
    while (getchar() != '\n');  // очистка буфера
    return ch;
}
