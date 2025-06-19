#include "rpn.h"

#include <math.h>
#include <stdlib.h>

#include "stack.h"
#include "structures.h"
#include "validation.h"

int shunting_yard(const Token* tokens, int token_count, Token* output, int* output_count) {
    Stack* stack = create_stack(token_count);
    int result = stack != NULL;
    *output_count = 0;

    for (int i = 0; result && i < token_count; i++) {
        Token token = tokens[i];

        if (token.type == 'n' || token.type == 'v') {
            output[(*output_count)++] = token;
        } else if (token.type == 'f' || token.type == 'u' || token.type == '(') {
            stack_push(stack, token);
        } else if (token.type == 'o') {
            result = handle_operator_for_shunting_yard(stack, token, output, output_count);
        } else if (token.type == ')') {
            result = handle_closing_bracket(stack, output, output_count);
        }
    }

    if (result) {
        result = process_remaining_stack(stack, output, output_count);
    }

    free_stack(stack);
    return result;
}

int handle_operator_for_shunting_yard(Stack* stack, Token token, Token* output, int* output_count) {
    while (!is_empty(stack) && peek(stack).type == 'o' &&
           get_precedence(token.operator) <= get_precedence(peek(stack).operator)) {
        output[(*output_count)++] = stack_pop(stack);
    }
    stack_push(stack, token);
    return 1;
}

int handle_closing_bracket(Stack* stack, Token* output, int* output_count) {
    while (!is_empty(stack) && peek(stack).type != '(') {
        output[(*output_count)++] = stack_pop(stack);
    }
    int success = 1;
    if (is_empty(stack)) success = 0;

    if (success) {
        stack_pop(stack);
        if (!is_empty(stack) && peek(stack).type == 'f') {
            output[(*output_count)++] = stack_pop(stack);
        }
    }
    return success;
}

int process_remaining_stack(Stack* stack, Token* output, int* output_count) {
    while (!is_empty(stack)) {
        if (peek(stack).type == '(') return 0;
        output[(*output_count)++] = stack_pop(stack);
    }
    return 1;
}

double evaluate_rpn(const Token* rpn_expr, int expr_length, double x_value) {
    Stack* stack = create_stack(expr_length);
    double result = 0.0;

    if (stack) {
        for (int i = 0; i < expr_length && !isnan(result); i++) {
            evaluate_rpn_push_operand(stack, rpn_expr[i], x_value);
            result = evaluate_rpn_process_operator(stack, rpn_expr[i], result);
        }
        result = (!isnan(result) && !is_empty(stack)) ? stack_pop(stack).value : result;
    }

    free_stack(stack);
    return result;
}

void evaluate_rpn_push_operand(Stack* stack, Token token, double x) {
    if (token.type == 'n') {
        stack_push(stack, (Token){'n', token.value, 0, "", 0});
    } else if (token.type == 'v') {
        stack_push(stack, (Token){'n', x, 0, "", 0});
    }
}

double evaluate_rpn_process_operator(Stack* stack, Token token, double current_result) {
    if (token.type == 'f') {
        if (!is_empty(stack)) {
            Token operand = stack_pop(stack);
            double res = apply_function(token.function, operand.value);
            if (isnan(res) || isinf(res)) return NAN;
            stack_push(stack, (Token){'n', res, 0, "", 0});
        }
        return current_result;
    }

    if (token.type == 'o') {
        if (!is_empty(stack)) {
            Token right = stack_pop(stack);
            if (!is_empty(stack)) {
                Token left = stack_pop(stack);
                double res = apply_operator(token.operator, left.value, right.value);
                if (isnan(res) || isinf(res)) return NAN;
                stack_push(stack, (Token){'n', res, 0, "", 0});
            } else {
                stack_push(stack, right);
            }
        }
        return current_result;
    }

    if (token.type == 'u') {
        if (!is_empty(stack)) {
            Token operand = stack_pop(stack);
            stack_push(stack, (Token){'n', -operand.value, 0, "", 0});
        }
    }

    return current_result;
}