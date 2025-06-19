#include <stdio.h>

#include "pong.h"

#define WIDTH 80
#define HEIGHT 25

int cong_graphic(int pl, int pr, int sc1, int sc2) {
    int paddle_l1 = pl;     // Центр левой ракетки 12
    int paddle_r1 = pr;     // Центр правой ракетки 12
    int score_left = sc1;   // Очки игрока слева
    int score_right = sc2;  // Очки игрока справа

    printf("                             CONGRATULATIONS, YOU WON!!!\n");
    printf("                                     %d | %d\n", score_left, score_right);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Верхняя и нижняя границы
            if (y == 0 || y == HEIGHT - 1) {
                printf("-");
            }

            // Левая и правая границы
            else if (x == 0 || x == WIDTH - 1) {
                printf("|");
            }

            // Левая ракетка: вертикальная, 3 символа: y-1, y, y+1, в колонке x == 2
            else if (x == 2 && (y == paddle_l1 - 1 || y == paddle_l1 || y == paddle_l1 + 1)) {
                printf("|");
            }

            // Правая ракетка: вертикальная, 3 символа: y-1, y, y+1, в колонке x == 77
            else if (x == 77 && (y == paddle_r1 - 1 || y == paddle_r1 || y == paddle_r1 + 1)) {
                printf("|");
            }

            // Остальное — пусто
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
