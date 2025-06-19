#include "stack.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validation.h"

Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    Stack* result = NULL;

    if (stack != NULL) {
        stack->data = (Token*)malloc(capacity * sizeof(Token));
        if (stack->data != NULL) {
            stack->top = -1;
            stack->capacity = capacity;
            result = stack;
        } else {
            free(stack);
        }
    }
    return result;
}

void stack_push(Stack* stack, Token token) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++stack->top] = token;
    }
}

Token stack_pop(Stack* stack) {
    Token result = {0};
    if (!is_empty(stack)) {
        result = stack->data[stack->top--];
    }
    return result;
}

Token peek(Stack* stack) {
    Token result = {0};
    if (!is_empty(stack)) {
        result = stack->data[stack->top];
    }
    return result;
}

int is_empty(Stack* stack) { return stack->top == -1; }

void free_stack(Stack* stack) {
    if (stack != NULL) {
        free(stack->data);
        free(stack);
    }
}

double apply_function(const char* func_name, double x) {
    double result = 0.0;

    if (strcmp(func_name, "sin") == 0) {
        result = sin(x);
    } else if (strcmp(func_name, "cos") == 0) {
        result = cos(x);
    } else if (strcmp(func_name, "tan") == 0) {
        result = tan(x);
        if (isnan(result) || isinf(result)) {
            result = NAN;
        }
    } else if (strcmp(func_name, "ctg") == 0) {
        if (sin(x) == 0) {
            result = NAN;
        } else {
            result = cos(x) / sin(x);
            if (isnan(result) || isinf(result)) {
                result = NAN;
            }
        }
    } else if (strcmp(func_name, "sqrt") == 0) {
        if (x < 0) {
            result = NAN;
        } else {
            result = sqrt(x);
        }
    } else if (strcmp(func_name, "ln") == 0) {
        if (x <= 0) {
            result = NAN;
        } else {
            result = log(x);
        }
    }

    return result;
}

int is_operator(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

int get_precedence(char op) {
    int result = 0;
    if (op == '*' || op == '/') {
        result = 2;
    } else if (op == '+' || op == '-') {
        result = 1;
    }
    return result;
}

double apply_operator(char op, double a, double b) {
    double result = 0.0;

    if (op == '+') {
        result = a + b;
    } else if (op == '-') {
        result = a - b;
    } else if (op == '*') {
        result = a * b;
    } else if (op == '/') {
        if (b == 0) {
            result = NAN;
        } else {
            result = a / b;
        }
    }

    return result;
}

int handle_number(const char* expr, int* pos, Token* tokens, int* token_count) {
    double number;
    if (!read_number(expr, pos, &number)) {
        return 0;
    }

    tokens[*token_count].type = 'n';
    tokens[*token_count].value = number;
    tokens[*token_count].precedence = 0;
    (*token_count)++;
    return 1;
}

int handle_minus(int* pos, Token* tokens, int* token_count) {
    int is_unary =
        (*token_count == 0 || tokens[*token_count - 1].type == 'o' || tokens[*token_count - 1].type == '(');

    tokens[*token_count].type = is_unary ? 'u' : 'o';
    tokens[*token_count].operator= '-';
    tokens[*token_count].precedence = is_unary ? 3 : 1;
    (*token_count)++;
    (*pos)++;
    return 1;
}

int handle_operator(char op, int* pos, Token* tokens, int* token_count) {
    tokens[*token_count].type = 'o';
    tokens[*token_count].operator= op;
    tokens[*token_count].precedence = (op == '*' || op == '/') ? 2 : 1;
    (*token_count)++;
    (*pos)++;
    return 1;
}

int handle_identifier(const char* expr, int* pos, Token* tokens, int* token_count) {
    char buffer[5];
    if (!read_identifier(expr, pos, buffer, sizeof(buffer))) {
        return 0;
    }

    if (strcmp(buffer, "x") == 0) {
        tokens[*token_count].type = 'v';
        tokens[*token_count].precedence = 0; 
    } else if (strcmp(buffer, "sin") == 0 || strcmp(buffer, "cos") == 0 || strcmp(buffer, "tan") == 0 ||
               strcmp(buffer, "ctg") == 0 || strcmp(buffer, "sqrt") == 0 || strcmp(buffer, "ln") == 0) {
        tokens[*token_count].type = 'f';
        strncpy(tokens[*token_count].function, buffer, 5);
        tokens[*token_count].precedence = 4;
    } else {
        return 0;
    }

    (*token_count)++;
    return 1;
}