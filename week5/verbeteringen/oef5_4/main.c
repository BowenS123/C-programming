/*
maak een sjabloon voor bedrijven om hun inkomen en uitgaven mee weer te geven.
Voorzie een header file waarin de NAME van het bedrijf, het YEAR van het verslag
en de ROW_COUNT kunnen worden aangepast.
*/

/*
Het geprinte verslag zou er zo ongeveer zo moeten uitzien:
    omzet van amazingCompany in 1998:
    uitgave         prijs
    huur            -5000
    salaris         -3000
    verkochte prod  10000
    ---------------------
    netto           2000
*/

//Hoe je de invulling voor de rows maakt (zoals "huur" en "-3000") mag je zelf kiezen voor zolang je eindigt met netto
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    printf("omzet van %s in %d:\n",NAME,YEAR);
    printf("uitgave\t\t\tprijs\n");
    int totaal;
    /*
    In deze oplossing heb ik ervoor gekozen om de inkomens en uitgaves random te genereren
    met evenveel van beide. Ik heb netto niet meegeteld in mijn aantal rows en elk inkomen 
    of uitgave noemt hetzelfde.

    Simpelere versies waarin elke row een vaste naam en vast bedrag heeft zijn ook in orde.
    */
    for(int i=0;i<ROW_COUNT/2;i++)
    {
        srand(time(NULL));
        int uitgave = -(rand() % 3000+500);
        totaal +=uitgave;
        printf("%s\t\t\t%d\n","verlore",uitgave);
    }
    for(int i=0;i<ROW_COUNT/2;i++)
    {
        srand(time(NULL)+5);
        int inkomen = (rand() % 5000+1000);
        totaal +=inkomen;
        printf("%s\t\t\t%d\n","inkomen",inkomen);
    }
    if((ROW_COUNT % 2)==1){
        printf("%s\t\t%d\n","extra uitgave",50);
    }
    printf("-----------------------------\n");
    printf("netto\t\t\t%d\n",totaal);
}