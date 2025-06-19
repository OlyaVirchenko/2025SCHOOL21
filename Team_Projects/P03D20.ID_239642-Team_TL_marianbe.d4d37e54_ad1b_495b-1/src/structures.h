#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <math.h>

typedef struct {
    char type;
    double value;
    char operator;
    char function[5];
    int precedence;
} Token;

typedef struct {
    char** field;
    int width;
    int height;
    double x_min;
    double x_max;
    double y_min;
    double y_max;
} GraphField;

typedef struct {
    Token* data;
    int top;
    int capacity;
} Stack;

#endif