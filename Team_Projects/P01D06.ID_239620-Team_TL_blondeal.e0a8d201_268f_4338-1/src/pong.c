#include "pong.h"

#include <stdio.h>

int main() {
    int ball_x = 39;
    int ball_y = 6;
    int ball_dx = -1;
    int ball_dy = 1;
    int paddle_l = 12;
    int paddle_r = 12;
    int first_score = 0;
    int second_score = 0;
    int sc1;
    int sc2;
    int check1;
    int check2;
    int end_game = 0;

    graphic(ball_x, ball_y, paddle_l, paddle_r, first_score, second_score);

    while (!end_game) {
        int flag = 0;
        do {
            printf("Ход 1 игрока\n");

            ball_dx = func_ball_dx(ball_x, ball_y, ball_dx, paddle_l, paddle_r, check1, check2);
            check1 = 0;
            check2 = 0;
            ball_dy = func_ball_dy(ball_y, ball_dy);

            ball_x = update_ball_x(ball_x, ball_dx);
            ball_y = update_ball_y(ball_y, ball_dy);

            paddle_l = func_paddle_l(paddle_l);

            sc1 = second_score;
            second_score = score2(second_score, ball_x);
            if (second_score != sc1) {
                ball_x = 39;
                ball_y = 6;
                ball_dx = -1;
                ball_dy = 1;
                paddle_l = 12;
                paddle_r = 12;
                graphic(ball_x, ball_y, paddle_l, paddle_r, first_score, second_score);
                flag = 1;
                check2 = 1;
                if (first_score == 21 || second_score == 21) {
                    end_game = 1;
                    cong_graphic(paddle_l, paddle_r, first_score, second_score);
                    return 0;
                }
                continue;
            }

            sc2 = first_score;
            first_score = score1(first_score, ball_x);
            if (first_score != sc2) {
                ball_x = 39;
                ball_y = 6;
                ball_dx = -1;
                ball_dy = 1;
                paddle_l = 12;
                paddle_r = 12;
                graphic(ball_x, ball_y, paddle_l, paddle_r, first_score, second_score);
                flag = 1;
                check1 = 1;
                if (first_score == 21 || second_score == 21) {
                    end_game = 1;
                    cong_graphic(paddle_l, paddle_r, first_score, second_score);
                    return 0;
                }
                continue;
            }

            printf("%d:%d\n", first_score, second_score);

            graphic(ball_x, ball_y, paddle_l, paddle_r, first_score, second_score);

            flag = 1;
        } while (!flag);
        flag = 0;
        do {
            printf("Ход 2 игрока\n");
            ball_dx = func_ball_dx(ball_x, ball_y, ball_dx, paddle_l, paddle_r, check1, check2, first_score,
                                   second_score);
            check1 = 0;
            check2 = 0;
            ball_dy = func_ball_dy(ball_y, ball_dy);

            ball_x = update_ball_x(ball_x, ball_dx);
            ball_y = update_ball_y(ball_y, ball_dy);

            paddle_r = func_paddle_r(paddle_r);

            sc1 = second_score;
            second_score = score2(second_score, ball_x);
            if (second_score != sc1) {
                ball_x = 39;
                ball_y = 6;
                ball_dx = -1;
                ball_dy = 1;
                paddle_l = 12;
                paddle_r = 12;
                graphic(ball_x, ball_y, paddle_l, paddle_r);
                flag = 1;
                check2 = 1;
                if (first_score == 21 || second_score == 21) {
                    cong_graphic(paddle_l, paddle_r, first_score, second_score);
                    return 0;
                }
                continue;
            }

            sc2 = first_score;
            first_score = score1(first_score, ball_x);
            if (first_score != sc2) {
                ball_x = 39;
                ball_y = 6;
                ball_dx = -1;
                ball_dy = 1;
                paddle_l = 12;
                paddle_r = 12;
                graphic(ball_x, ball_y, paddle_l, paddle_r, first_score, second_score);
                flag = 1;
                check1 = 1;
                if (first_score == 21 || second_score == 21) {
                    cong_graphic(paddle_l, paddle_r, first_score, second_score);
                    return 0;
                }
                continue;
            }
            printf("%d:%d\n", first_score, second_score);

            graphic(ball_x, ball_y, paddle_l, paddle_r, first_score, second_score);
            flag = 1;
        } while (!flag);
    }

    return 0;
}
