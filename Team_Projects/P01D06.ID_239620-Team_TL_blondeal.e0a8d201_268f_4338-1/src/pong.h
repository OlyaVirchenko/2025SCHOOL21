#ifndef PONG_H
#define PONG_H

char input();

int graphic();
int cong_graphic();

int func_paddle_l();
int func_paddle_r();

int func_ball_dx();
int func_ball_dy();

int update_ball_x();
int update_ball_y();

int score1();
int score2();

int end_game();

#endif
