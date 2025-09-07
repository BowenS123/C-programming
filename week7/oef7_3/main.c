#include <stdio.h>
#include <time.h>
#include <ctype.h>
//zelfde opgave als 1 maar nu moet de maand en het jaartal ook random zijn
// maanden januari-december, jaren 1990-2025
int main()
{
    srand(time(NULL));
    char datum[20];
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char array[] = {'0','1','2','3','4','5','6','7','8','9'}; 
    int tientallen = rand() % 4;
    int eenheden;
    char jaar[] = "1990";
    char maand[15];
    char dag[] = "01";

    if(tientallen==3)
    {
        eenheden = rand() %2;
    }
    else
    {
        eenheden = rand() %10;
    }
    printf("dag: %d%d\n",tientallen,eenheden);
    dag[0] = array[tientallen];
    dag[1] = array[eenheden];

    strcpy(maand,months[rand() %12]);

    int eeuw = rand() % 2;
    if(eeuw==0)
    {
        jaar[0] = array[1];
        jaar[1] = array[9];
        jaar[2] = array[9];
        jaar[3] = array[rand() %10];
    }
    else
    {
        jaar[0] = array[2];
        jaar[1] = array[0];

        jaar[2] = array[rand() % 3];
        if(jaar[2] =='2')
        {
            jaar[3] = array[rand() % 6];
        }
        else
        {
            jaar[3] = array[rand() % 10];
        }
    }

    strcpy(datum,dag);
    strcat(datum," ");
    strcat(datum,maand);
    strcat(datum," ");  
    strcat(datum,jaar);

    printf("%s",datum);

}