#include "minesweeper.h"

int main()
{
    int option;
    while( 1 )
    {
        printf("Welcome to Minesweeper!\n");
        printf("-----------------------------------\n");
        printf("| Choose a option between (1 or 2)|\n");
        printf("| 1. New Game                     |\n");
        printf("| 2. Quit                         |\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        if (option == 1) 
        {
            startNewGame();
            initializeBoard();
            printBoard();
            placeBombs();
            performActions();
        }
        else if (option == 2) 
        {
            printf("Quiting...\n");
            return 0;  
        }
        else 
        {
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}