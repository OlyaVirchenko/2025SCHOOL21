#ifndef RPN_H
#define RPN_H

#include "structures.h"

int shunting_yard(const Token* tokens, int token_count, Token* output, int* output_count);
double evaluate_rpn(const Token* rpn_expr, int expr_length, double x_value);
int handle_operator_for_shunting_yard(Stack* stack, Token token, Token* output, int* output_count);
int handle_closing_bracket(Stack* stack, Token* output, int* output_count);
int process_remaining_stack(Stack* stack, Token* output, int* output_count);
void evaluate_rpn_push_operand(Stack* stack, Token token, double x);
double evaluate_rpn_process_operator(Stack* stack, Token token, double current_result);

#endif