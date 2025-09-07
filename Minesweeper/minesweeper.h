#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_INPUT 10                   // Max length input
#define MAX_SIZE 15                     // Max board size
#define DEFAULT_BOMB_PERCENTAGE 25

// Macros
#define EMPTY_CELL '.'
#define BOMB_CELL 'B'
#define FLAG_CELL 'F'
#define UNREVEALED_CELL '.'

// Enums
typedef enum
{
    ACTION_OPEN = 'O',
    ACTION_FLAG = 'F',
    ACTION_QUIT = 'Q'
} PlayerAction;

// Global variables
int boardHeight, boardWidth;            // Board dimensions
int totalBombs;                         // Numbers of bombs
char bombBoard[MAX_SIZE][MAX_SIZE];     // Bomb locations
char playerBoard[MAX_SIZE][MAX_SIZE];   // Player vieuw of board
char flagBoard[MAX_SIZE][MAX_SIZE];     // Flags placed by player

// Function prototypes
void startNewGame();
void initializeBoard();
void placeBombs();
void printBoard();
void performActions();
void revealCell(int x, int y);
void floodFill(int x, int y);
int isValidCoordinate(int x, int y);
int checkWinCondition();
void revealEntireBoard();

// Initialize a new game
void startNewGame()
{
    int sizeChoice;
    do
    {
        //choosing board size
        printf("Select board size:\n");
        printf("1. Small (5x5)\n");
        printf("2. Medium (8x8)\n");
        printf("3. Large (15x15)\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &sizeChoice);
        switch (sizeChoice)
        {
            case 1:
            {
                boardHeight = 5;
                boardWidth = 5;
                break;
            }
            case 2:
            {
                boardHeight = 8;
                boardWidth = 8;
                break;
            }
            case 3:
            {
                boardHeight = 15;
                boardWidth = 15;
                break;
            }
            default:
            {
                printf("Invalid choice, try again.\n");
                continue;
            }
        }
        break;
    }
    while (sizeChoice < 1 || sizeChoice > 3);
    // how many bombs
    do
    {
        printf("How many bombs to place on the board (max %d)?\n", (boardHeight * boardWidth - 1));
        printf("Enter 0 for the default (25%% bombs on the board).\n");
        scanf("%d", &totalBombs);

        if (totalBombs == 0)
        {
            // 25% of the bombs calculated
            totalBombs = (boardHeight * boardWidth) / 4;
            break;
        }
        // check for total bombs is not over max from boardsizes
        if (totalBombs > (boardHeight * boardWidth - 1) || totalBombs < 0)
        {
            printf("Invalid input, try again.\n");
        }
    }
    while (totalBombs > (boardHeight * boardWidth - 1) || totalBombs < 0);

    printf("New game started with a %dx%d board and %d bombs.\n", boardHeight, boardWidth, totalBombs);
}

// Initialize the board
void initializeBoard()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            bombBoard[i][j] = EMPTY_CELL;
            playerBoard[i][j] = UNREVEALED_CELL;
            flagBoard[i][j] = '0';
        }
    }
}

// Randomly place bombs on the board
void placeBombs()
{
    srand(time(NULL));
    int bombsPlaced = 0;
    while (bombsPlaced < totalBombs)
    {
        int x = rand() % boardHeight;
        int y = rand() % boardWidth;
        // Check if there's bomb, no bomb place bomb
        if (bombBoard[x][y] != BOMB_CELL)
        {
            bombBoard[x][y] = BOMB_CELL;
            bombsPlaced++;
        }
    }

    // Calculate numbers around bombs
    for (int i = 0; i < boardHeight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            //If there is bomb skip bomb cell
            if (bombBoard[i][j] == BOMB_CELL)
            {
                continue;
            }
            int bombCount = 0;

            // Loop through the 8 surrounding cells (horizontal, vertical, and diagonal)
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    int nx = i + dx, ny = j + dy;
                    //numbers around bomb cell counted up
                    if (bombBoard[nx][ny] == BOMB_CELL)
                    {
                        bombCount++;
                    }
                }
            }
            bombBoard[i][j] = bombCount + '0';
        }
    }
}

// Print the player's board
void printBoard()
{
    printf("\n    ");
    for (int i = 0; i < boardWidth; i++)
    {
        printf("|%c|", 'A' + i);
    }
    printf("\n   ");
    for (int j = 0; j < boardWidth; j++)
    {
        printf("---");
    }
    printf("--\n");

    for (int x = 0; x < boardHeight; x++)
    {
        printf("%2d |", x);
        for (int y = 0; y < boardWidth; y++)
        {
            if (flagBoard[x][y] == '1')
            {
                printf("|%c|", FLAG_CELL);
            }
            else if (playerBoard[x][y] == UNREVEALED_CELL)
            {
                printf("|%c|", UNREVEALED_CELL);
            }
            else
            {
                printf(" %c ", playerBoard[x][y]); 
            }
        }
        printf("|\n");
    }

    printf("   ");
    for (int i = 0; i < boardWidth; i++)
    {
        printf("---");
    }
    printf("--\n");
}

// Check if coordinates are within bounds
int isValidCoordinate(int x, int y)
{
    return x >= 0 && x < boardHeight && y >= 0 && y < boardWidth;
}

void performActions()
{
    char inputAction;
    char input[MAX_INPUT];
    int x, y;

    while (1)
    {
        printf("Actions: [O]pen, [F]lag, [Q]uit\n");
        printf("Enter your action: ");
        scanf(" %c", &inputAction);
        // Uppercase letters the input
        PlayerAction action = toupper(inputAction);

        switch (action)
        {
            //Opening cell
            case ACTION_OPEN:
            {
                printf("Enter coordinates to open a cell (for example: A 1): ");
                scanf(" %c %d", &input[0], &x); 
                // Convert the column letter to an index
                y = toupper(input[0]) - 'A';
                //check coordinates are valid
                if (isValidCoordinate(x, y))
                {
                    // bomb got hit
                    if (bombBoard[x][y] == BOMB_CELL)
                    {
                        printf("You hit a bomb! Game over!\n");
                        revealEntireBoard();
                        return;
                    }
                    else
                    {
                    revealCell(x, y);
                    printBoard();
                    }
                    // you won
                    if (checkWinCondition())
                    {
                        printf("Congratulations, you won!\n");
                        revealEntireBoard();
                        return;
                    }
                }
                else
                {
                    printf("Invalid coordinates. Try again.\n");
                }
                break;
            }
            //Placing flag
            case ACTION_FLAG: 
            {
                printf("Enter coordinates to place/remove a flag (e.g., A 1): ");
                scanf(" %c %d", &input[0], &x);
                y = toupper(input[0]) - 'A';
                if (playerBoard[x][y] != UNREVEALED_CELL)
                {
                    printf("Cannot place a flag on an already revealed cell!\n");
                }
                else if (isValidCoordinate(x, y))
                {
                    //choosing flag place or remove
                    flagBoard[x][y] = (flagBoard[x][y] == '1') ? '0' : '1';
                    printBoard(); 
                }
                else
                {
                    printf("Invalid coordinates. Try again.\n");
                }
                break;
            }
            // Quiting game
            case ACTION_QUIT:
            {
                printf("You quit the game.\n");
                return;
            }
            default:
            {
                printf("Invalid action. Please enter [O], [F], or [Q].\n");
                break;
            }
        }

        // Clear input buffer
        while (getchar() != '\n');
    }
}

// Reveal a cell and handle empty spaces
void revealCell(int x, int y)
{
    
    if (flagBoard[x][y] == '1')
    {
        printf("Cannot open this cell: it is flagged!\n");
        return;
    }

    if (playerBoard[x][y] != UNREVEALED_CELL)
    {
        printf("This cell is already revealed.\n");
        return;
    }
    //reveal de number of cell
    playerBoard[x][y] = bombBoard[x][y];
    //if number = 0 activate flood fill
    if (bombBoard[x][y] == '0')
    {
        floodFill(x, y);
    }
}

// Flood fill to reveal empty cells
void floodFill(int x, int y)
{
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx, ny = y + dy;
            if (playerBoard[nx][ny] == UNREVEALED_CELL)
            {
                revealCell(nx, ny);
            }
        }
    }
}

// Check win
int checkWinCondition() {
    for (int i = 0; i < boardHeight; i++)
    {
        for (int j = 0; j < boardWidth; j++) 
        {
            if (playerBoard[i][j] == UNREVEALED_CELL && bombBoard[i][j] != BOMB_CELL)
            {
                return 0;
            }
        }
    }
    return 1;
}

// revealing the board
void revealEntireBoard()
{
    for (int i = 0; i < boardHeight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            playerBoard[i][j] = bombBoard[i][j];
        }
    }
    printBoard();
}
