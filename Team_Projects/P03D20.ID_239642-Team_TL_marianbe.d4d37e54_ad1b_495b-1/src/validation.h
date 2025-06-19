#ifndef VALIDATION_H
#define VALIDATION_H

#include "structures.h"

int validate_expression(const char* expr);
int is_valid_character(char c);
int is_digit(char c);
int is_letter(char c);
int is_whitespace(char c);

int read_number(const char* expr, int* pos, double* value);
int read_identifier(const char* expr, int* pos, char* buffer, int max_len);

#endif