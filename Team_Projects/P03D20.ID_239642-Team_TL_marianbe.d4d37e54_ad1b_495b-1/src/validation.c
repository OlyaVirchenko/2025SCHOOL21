#include "validation.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_expression(const char* expr) {
    int result = 1;

    if (!expr || strlen(expr) == 0) {
        result = 0;
    } else {
        int balance = 0;
        for (int i = 0; expr[i] != '\0' && result; i++) {
            if (expr[i] == '(') {
                balance++;
            } else if (expr[i] == ')') {
                balance--;
                if (balance < 0) {
                    result = 0;
                }
            }
        }

        if (balance != 0) {
            result = 0;
        } else {
            for (int i = 0; expr[i] != '\0' && result; i++) {
                if (!is_valid_character(expr[i])) {
                    result = 0;
                }
            }
        }
    }

    return result;
}

int is_valid_character(char c) { return is_digit(c) || is_letter(c) || strchr("+-*/(). ", c); }

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int is_letter(char c) { return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')); }

int is_whitespace(char c) { return (c == ' ' || c == '\t' || c == '\n'); }

int read_number(const char* expr, int* pos, double* value) {
    int result = 0;

    if (expr && pos && value) {
        char* endptr;
        *value = strtod(expr + *pos, &endptr);

        if (endptr != expr + *pos) {
            *pos += (int)(endptr - (expr + *pos));
            result = 1;
        }
    }

    return result;
}

int read_identifier(const char* expr, int* pos, char* buffer, int max_len) {
    int result = 0;

    if (is_letter(expr[*pos])) {
        int index = 0;
        while (expr[*pos] && is_letter(expr[*pos]) && index < max_len - 1) {
            char c = expr[*pos];
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
            buffer[index] = c;
            index++;
            (*pos)++;
        }
        buffer[index] = '\0';
        result = 1;
    }

    return result;
}
