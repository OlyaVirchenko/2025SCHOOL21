#include <stdio.h>

#include "pong.h"

int func_paddle_l(int paddle_l) {
    char key = input();

    if (key == 'a' && paddle_l != 2) {
        return paddle_l - 2;
    } else if (key == 'z' && paddle_l != 22) {
        return paddle_l + 2;
    }
    return paddle_l;
}

int func_paddle_r(int paddle_r) {
    char key = input();

    if (key == 'k' && paddle_r != 2) {
        return paddle_r - 2;
    } else if (key == 'm' && paddle_r != 22) {
        return paddle_r + 2;
    }
    return paddle_r;
}

int update_ball_x(int x, int dx) { return x + dx; }

int update_ball_y(int y, int dy) { return y + dy; }

int func_ball_dx(int x, int y, int dx, int paddle_l, int paddle_r, int check1, int check2) {
    if (check1 == 1 || check2 == 1) {
        dx = -dx;
    }

    if (x == 3 && (y >= paddle_l - 1 && y <= paddle_l + 1)) {
        return -dx;
    } else if (x == 76 && (y >= paddle_r - 1 && y <= paddle_r + 1)) {
        return -dx;
    }

    return dx;
}

int func_ball_dy(int y, int dy) {
    if (y == 1 || y == 23) {
        return -dy;
    }
    return dy;
}

int score2(int second_score, int ball__x) {
    if (ball__x == 0) {
        return second_score + 1;
    }
    return second_score;
}

int score1(int first_score, int ball__x) {
    if (ball__x == 79) {
        return first_score + 1;
    }
    return first_score;
}
