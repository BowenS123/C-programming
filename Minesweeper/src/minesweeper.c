#include "minesweeper.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_MINE_PERCENTAGE 25
#define INPUT_SIZE 64
#define MINE_CELL 'B'
#define EMPTY_CELL '0'

static bool read_integer(const char *prompt, int *value)
{
    char input[INPUT_SIZE];
    char trailing;

    printf("%s", prompt);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return false;
    }

    if (sscanf(input, " %d %c", value, &trailing) != 1) {
        printf("Please enter a whole number.\n");
        return false;
    }
    return true;
}

static bool read_coordinate(const char *prompt, int *row, int *column)
{
    char input[INPUT_SIZE];
    char column_letter;
    char trailing;

    printf("%s", prompt);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return false;
    }

    if (sscanf(input, " %c %d %c", &column_letter, row, &trailing) != 2) {
        printf("Use a coordinate such as A 1.\n");
        return false;
    }

    column_letter = (char)toupper((unsigned char)column_letter);
    *column = column_letter - 'A';
    return true;
}

static bool is_valid_coordinate(const Game *game, int row, int column)
{
    return row >= 0 && row < game->height && column >= 0 &&
           column < game->width;
}

static int count_adjacent_mines(const Game *game, int row, int column)
{
    int count = 0;

    for (int row_offset = -1; row_offset <= 1; ++row_offset) {
        for (int column_offset = -1; column_offset <= 1; ++column_offset) {
            int adjacent_row = row + row_offset;
            int adjacent_column = column + column_offset;
            if (is_valid_coordinate(game, adjacent_row, adjacent_column) &&
                game->mines[adjacent_row][adjacent_column] == MINE_CELL) {
                ++count;
            }
        }
    }
    return count;
}

static void initialize_game(Game *game, int height, int width, int mines)
{
    game->height = height;
    game->width = width;
    game->total_mines = mines;

    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            game->mines[row][column] = EMPTY_CELL;
            game->revealed[row][column] = false;
            game->flagged[row][column] = false;
        }
    }
}

static void place_mines(Game *game)
{
    int placed = 0;
    while (placed < game->total_mines) {
        int row = rand() % game->height;
        int column = rand() % game->width;
        if (game->mines[row][column] != MINE_CELL) {
            game->mines[row][column] = MINE_CELL;
            ++placed;
        }
    }

    for (int row = 0; row < game->height; ++row) {
        for (int column = 0; column < game->width; ++column) {
            if (game->mines[row][column] != MINE_CELL) {
                game->mines[row][column] =
                    (char)('0' + count_adjacent_mines(game, row, column));
            }
        }
    }
}

static void print_board(const Game *game, bool reveal_mines)
{
    printf("\n    ");
    for (int column = 0; column < game->width; ++column) {
        printf(" %c ", (char)('A' + column));
    }
    printf("\n   ");
    for (int column = 0; column < game->width; ++column) {
        printf("---");
    }
    printf("\n");

    for (int row = 0; row < game->height; ++row) {
        printf("%2d ", row);
        for (int column = 0; column < game->width; ++column) {
            char display = '.';
            if (reveal_mines && game->mines[row][column] == MINE_CELL) {
                display = MINE_CELL;
            } else if (game->flagged[row][column]) {
                display = 'F';
            } else if (game->revealed[row][column]) {
                display = game->mines[row][column];
            }
            printf("|%c|", display);
        }
        printf("\n");
    }
    printf("\n");
}

static void reveal_cell(Game *game, int row, int column)
{
    if (!is_valid_coordinate(game, row, column) ||
        game->revealed[row][column] || game->flagged[row][column]) {
        return;
    }

    game->revealed[row][column] = true;
    if (game->mines[row][column] != EMPTY_CELL) {
        return;
    }

    for (int row_offset = -1; row_offset <= 1; ++row_offset) {
        for (int column_offset = -1; column_offset <= 1; ++column_offset) {
            reveal_cell(game, row + row_offset, column + column_offset);
        }
    }
}

static bool has_won(const Game *game)
{
    for (int row = 0; row < game->height; ++row) {
        for (int column = 0; column < game->width; ++column) {
            if (game->mines[row][column] != MINE_CELL &&
                !game->revealed[row][column]) {
                return false;
            }
        }
    }
    return true;
}

static bool configure_game(Game *game)
{
    int size_choice;
    int dimensions[] = {0, 5, 8, 15};
    do {
        if (!read_integer(
                "\nBoard size: 1) Small (5x5), 2) Medium (8x8), "
                "3) Large (15x15): ",
                &size_choice)) {
            continue;
        }
        if (size_choice < 1 || size_choice > 3) {
            printf("Choose 1, 2, or 3.\n");
        }
    } while (size_choice < 1 || size_choice > 3);

    int size = dimensions[size_choice];
    int mine_count;
    int maximum_mines = size * size - 1;
    char prompt[INPUT_SIZE];
    do {
        snprintf(prompt, sizeof(prompt),
                 "Mines (1-%d, or 0 for %d%%): ", maximum_mines,
                 DEFAULT_MINE_PERCENTAGE);
        if (!read_integer(prompt, &mine_count)) {
            mine_count = -1;
            continue;
        }
        if (mine_count == 0) {
            mine_count = size * size * DEFAULT_MINE_PERCENTAGE / 100;
        }
        if (mine_count < 1 || mine_count > maximum_mines) {
            printf("Choose between 1 and %d mines, or 0 for the default.\n",
                   maximum_mines);
        }
    } while (mine_count < 1 || mine_count > maximum_mines);

    initialize_game(game, size, size, mine_count);
    place_mines(game);
    return true;
}

static void play_game(Game *game)
{
    char input[INPUT_SIZE];
    print_board(game, false);

    for (;;) {
        char action_character;
        printf("Action: [O]pen, [F]lag, [Q]uit: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return;
        }
        if (sscanf(input, " %c", &action_character) != 1) {
            printf("Enter O, F, or Q.\n");
            continue;
        }

        PlayerAction action = (PlayerAction)toupper(
            (unsigned char)action_character);
        if (action == ACTION_QUIT) {
            printf("You quit the game.\n");
            return;
        }
        if (action != ACTION_OPEN && action != ACTION_FLAG) {
            printf("Enter O, F, or Q.\n");
            continue;
        }

        int row;
        int column;
        const char *prompt = action == ACTION_OPEN
                                 ? "Coordinate to open (for example A 1): "
                                 : "Coordinate to flag/unflag: ";
        if (!read_coordinate(prompt, &row, &column) ||
            !is_valid_coordinate(game, row, column)) {
            printf("That coordinate is outside the board.\n");
            continue;
        }

        if (action == ACTION_FLAG) {
            if (game->revealed[row][column]) {
                printf("A revealed cell cannot be flagged.\n");
            } else {
                game->flagged[row][column] = !game->flagged[row][column];
                print_board(game, false);
            }
            continue;
        }

        if (game->flagged[row][column]) {
            printf("Unflag the cell before opening it.\n");
            continue;
        }
        if (game->mines[row][column] == MINE_CELL) {
            printf("You hit a mine. Game over.\n");
            print_board(game, true);
            return;
        }

        reveal_cell(game, row, column);
        print_board(game, false);
        if (has_won(game)) {
            printf("Congratulations, you cleared the board!\n");
            print_board(game, true);
            return;
        }
    }
}

void game_run(void)
{
    srand((unsigned int)time(NULL));

    for (;;) {
        int option;
        printf("\n=== Minesweeper ===\n");
        printf("1. New game\n");
        printf("2. Quit\n");
        if (!read_integer("Choose an option: ", &option)) {
            continue;
        }
        if (option == 2) {
            printf("Goodbye.\n");
            return;
        }
        if (option != 1) {
            printf("Choose 1 or 2.\n");
            continue;
        }

        Game game;
        if (configure_game(&game)) {
            play_game(&game);
        }
    }
}
