#include <stdio.h>
/*
    voeg code toe zodat er een 5 bij 5 array van 'O' geprint wordt.
    De gebruiker kan vervolgens een coordinaat ingeven die dan in de
    array vervangen wordt met een 'X'
*/
int main()
{
    char array[5][5];
    for(int i = 0; i < 5;i++)
    {
        for(int j = 0; j < 5;j++)
        {
            array[i][j] = 'O';
        }
    }
    int x,y;
    printf("geef x: \n");
    scanf("%d",&x);
    printf("geef y: \n");
    scanf("%d",&y);
    array[y-1][x-1] = 'X'; //index start van 0 (ok als je gwn x en y geeft)
    for(int row = 0;row<5;row++)
    {
        for(int col = 0;col<5;col++)
        {
            printf("%c\t",array[row][col]);
        }
        printf("\n");
    }
}