#ifndef GRAPH_H
#define GRAPH_H

#include "structures.h"

#define MAX_LEN_EXPR 120
#define WIDTH 80
#define HEIGHT 25

int main(int argc, char* argv[]);
void draw_screen(const char* expression);

int parsing_expression(const char* expr, Token* tokens, int* token_count);
int validate_expression(const char* expr);
int process_graph_points(GraphField* field, Token* expression_rpn, int rpn_count);

void init_graph_field(GraphField* field);
void render_graph(GraphField* field);
void free_graph_field(GraphField* field);

int x_to_screen(double x, GraphField* field);
int y_to_screen(double y, GraphField* field);
double screen_to_x(int screen_x, GraphField* field);

#endif