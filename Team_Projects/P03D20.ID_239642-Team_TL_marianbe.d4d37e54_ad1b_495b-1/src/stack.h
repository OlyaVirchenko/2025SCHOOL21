#ifndef STACK_H
#define STACK_H

#include "structures.h"

Stack* create_stack(int capacity);
void stack_push(Stack* stack, Token token);
Token stack_pop(Stack* stack);
Token peek(Stack* stack);
int is_empty(Stack* stack);
void free_stack(Stack* stack);

double apply_function(const char* func_name, double x);
double apply_operator(char op, double a, double b);

int is_operator(char c);
int get_precedence(char op);

int handle_number(const char* expr, int* pos, Token* tokens, int* token_count);
int handle_minus(int* pos, Token* tokens, int* token_count);
int handle_operator(char op, int* pos, Token* tokens, int* token_count);
int handle_identifier(const char* expr, int* pos, Token* tokens, int* token_count);

#endif