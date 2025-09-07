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

#include <stdio.h>
#include "company_report.h"

int main()
{
    printf("omzet van %s in %d:\n", NAME, YEAR);
    printf("uitgave\t\tprijs\n");

    printf("%s\t\t%d\n", ROW_1_NAME, ROW_1_VALUE);
    printf("%s\t\t%d\n", ROW_2_NAME, ROW_2_VALUE);
    printf("%s\t%d\n", ROW_3_NAME, ROW_3_VALUE);

    int netto = ROW_1_VALUE + ROW_2_VALUE + ROW_3_VALUE;

    printf("---------------------\n");
    printf("netto\t\t%d\n", netto);

    return 0;
}