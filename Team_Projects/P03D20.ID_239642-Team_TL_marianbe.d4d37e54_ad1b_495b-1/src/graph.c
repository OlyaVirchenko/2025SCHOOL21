#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rpn.h"
#include "stack.h"
#include "validation.h"

int main(int argc, char* argv[]) {
    char str_math_expr[MAX_LEN_EXPR];
    int result = 0;
    int expression_ready = 0;

    if (argc == 2) {
        strncpy(str_math_expr, argv[1], MAX_LEN_EXPR - 1);
        str_math_expr[MAX_LEN_EXPR - 1] = '\0';
        expression_ready = 1;
    } else {
        printf("Введите математическое выражение: ");
        if (fgets(str_math_expr, MAX_LEN_EXPR, stdin) != NULL) {
            str_math_expr[strcspn(str_math_expr, "\n")] = '\0';
            expression_ready = 1;
        }
    }

    if (expression_ready) {
        if (!validate_expression(str_math_expr)) {
            printf("n/a");
        } else {
            draw_screen(str_math_expr);
        }
    }

    return result;
}

void draw_screen(const char* expression) {
    Token tokens[MAX_LEN_EXPR];
    int token_count = 0;
    int success_draw = 1;

    if (!parsing_expression(expression, tokens, &token_count)) {
        printf("n/a");
        success_draw = 0;
    }

    if (success_draw) {
        GraphField field;
        init_graph_field(&field);

        Token expression_rpn[MAX_LEN_EXPR];
        int rpn_count = 0;

        if (!shunting_yard(tokens, token_count, expression_rpn, &rpn_count)) {
            printf("n/a");
            success_draw = 0;
        }

        int has_valid_point = process_graph_points(&field, expression_rpn, rpn_count);

        if (!success_draw || !has_valid_point) {
            printf("n/a");
        } else {
            render_graph(&field);
        }

        free_graph_field(&field);
    }
}

int process_graph_points(GraphField* field, Token* expression_rpn, int rpn_count) {
    int has_valid_point = 0;
    for (int screen_x = 0; screen_x < field->width; screen_x++) {
        double x = screen_to_x(screen_x, field);
        double y = evaluate_rpn(expression_rpn, rpn_count, x);
        if (!isnan(y) && y >= field->y_min && y <= field->y_max) {
            has_valid_point = 1;
            int screen_y = y_to_screen(y, field);
            if (screen_y >= 0 && screen_y < field->height) {
                field->field[screen_y][screen_x] = '*';
            }
        }
    }
    return has_valid_point;
}

int parsing_expression(const char* expr, Token* tokens, int* token_count) {
    int pos = 0, success = 1;
    *token_count = 0;

    while (success && expr[pos]) {
        char c = expr[pos];
        if (is_whitespace(c))
            pos++;
        else if (!is_valid_character(c))
            success = 0;
        else if (is_digit(c) || c == '.')
            success = handle_number(expr, &pos, tokens, token_count);
        else if (c == '-')
            success = handle_minus(&pos, tokens, token_count);
        else if (is_operator(c))
            success = (*token_count && tokens[*token_count - 1].type != 'o')
                          ? handle_operator(c, &pos, tokens, token_count)
                          : 0;
        else if (is_letter(c))
            success = handle_identifier(expr, &pos, tokens, token_count);
        else if (c == '(' || c == ')') {
            tokens[(*token_count)++] = (Token){c, 0, 0, "", 0};
            pos++;
        } else
            success = 0;
    }

    if (success && *token_count > 0) {
        success = tokens[*token_count - 1].type != 'o' && tokens[*token_count - 1].type != 'u';
        for (int i = 0; success && i < *token_count - 1; i++) {
            int invalid_pair = (tokens[i].type == '(' && tokens[i + 1].type == ')');
            int invalid_func =
                (tokens[i].type == 'f' && (i + 1 >= *token_count || tokens[i + 1].type != '('));
            success = !(invalid_pair || invalid_func);
        }
    }

    return success;
}

void init_graph_field(GraphField* field) {
    field->width = WIDTH;
    field->height = HEIGHT;
    field->x_min = 0;
    field->x_max = 4 * M_PI;
    field->y_min = -1.0;
    field->y_max = 1.0;

    field->field = (char**)malloc(field->height * sizeof(char*));
    for (int i = 0; i < field->height; i++) {
        field->field[i] = (char*)malloc(field->width * sizeof(char));
        memset(field->field[i], '.', field->width);
    }
}

void render_graph(GraphField* field) {
    for (int y = 0; y < field->height; y++) {
        for (int x = 0; x < field->width; x++) {
            putchar(field->field[y][x]);
        }
        putchar('\n');
    }
}

void free_graph_field(GraphField* field) {
    if (field->field != NULL) {
        for (int i = 0; i < field->height; i++) {
            free(field->field[i]);
        }
        free(field->field);
        field->field = NULL;
    }
}

int y_to_screen(double y, GraphField* field) {
    int result = (int)round((y - field->y_min) / (field->y_max - field->y_min) * (field->height - 1));
    if (result < 0) result = 0;
    if (result >= field->height) result = field->height - 1;
    return result;
}

double screen_to_x(int screen_x, GraphField* field) {
    return field->x_min + (double)screen_x / (field->width - 1) * (field->x_max - field->x_min);
}