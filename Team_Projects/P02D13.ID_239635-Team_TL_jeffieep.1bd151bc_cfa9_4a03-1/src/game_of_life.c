#include <ncurses.h>
#include <stdio.h>

#define ROWS 25
#define COLS 80
#define DELAY_MIN 10
#define DELAY_MAX 1000

void read_file(int board1[ROWS][COLS]);
void check_neighbours(int board1[ROWS][COLS], int board2[ROWS][COLS]);
void graphic(int board1[ROWS][COLS]);

int main() {
  int board1[ROWS][COLS];
  int board2[ROWS][COLS];
  int delay = 100;
  int flag = 1;
  int ch;
  // Инициализация и настройка консоли ncurses
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  curs_set(0);

  // Функционал
  read_file(board1);
  freopen("/dev/tty", "r", stdin); // Передаёт ввод на терминал
  graphic(board1);

  while (flag) {
    if ((ch = getch()) == ' ') {
      flag = 0;
    } else if (ch == 'A' || ch == 'a') { // Ускорение
      if (delay > DELAY_MIN)
        delay -= 10;
    } else if (ch == 'Z' || ch == 'z') { // Замедление
      if (delay < DELAY_MAX)
        delay += 10;
    }

    check_neighbours(board1, board2);
    graphic(board2);

    for (int i = 0; i < ROWS; i++)
      for (int j = 0; j < COLS; j++)
        board1[i][j] = board2[i][j];

    napms(delay);
  }

  endwin();
  return 0;
}

void read_file(int board1[ROWS][COLS]) {
  int c;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      do {
        c = getch();
        if (c == EOF) {
          board1[i][j] = 0;
          break;
        }
      } while (c != '1' && c != '0');

      if (c == '0') {
        board1[i][j] = 0;
      } else if (c == '1') {
        board1[i][j] = 1;
      }
    }
  }
}

void check_neighbours(int board1[ROWS][COLS], int board2[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int i_plus = (i + 1) % ROWS;
      int i_minus = (i - 1 + ROWS) % ROWS;
      int j_plus = (j + 1) % COLS;
      int j_minus = (j - 1 + COLS) % COLS;

      int sum_neighbours = board1[i_plus][j_plus] + board1[i_plus][j_minus] +
                           board1[i_plus][j] + board1[i_minus][j] +
                           board1[i_minus][j_minus] + board1[i_minus][j_plus] +
                           board1[i][j_plus] + board1[i][j_minus];

      if ((sum_neighbours == 2 && board1[i][j] == 1) || sum_neighbours == 3) {
        board2[i][j] = 1;
      } else {
        board2[i][j] = 0;
      }
    }
  }
}

void graphic(int board1[ROWS][COLS]) {
  erase();
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (i == 0 || i == ROWS - 1) {
        addch('*');
      } else if (j == 0 || j == COLS - 1) {
        addch('*');
      } else if (board1[i][j]) {
        addch('O');
      } else {
        addch(' ');
      }
    }
    addch('\n');
  }
  refresh();
}
