#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <stdbool.h>

#define MINESWEEPER_MAX_SIZE 15

typedef enum {
    ACTION_OPEN = 'O',
    ACTION_FLAG = 'F',
    ACTION_QUIT = 'Q'
} PlayerAction;

typedef struct {
    int height;
    int width;
    int total_mines;
    char mines[MINESWEEPER_MAX_SIZE][MINESWEEPER_MAX_SIZE];
    bool revealed[MINESWEEPER_MAX_SIZE][MINESWEEPER_MAX_SIZE];
    bool flagged[MINESWEEPER_MAX_SIZE][MINESWEEPER_MAX_SIZE];
} Game;

void game_run(void);

#endif
