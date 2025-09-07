#include <stdio.h>
#include <ctype.h>
//de toupper(char) functie van ctype.h maakt een hoofdletter van een kleine letter
//je moet ctype.h niet uit je hoofd kennen
//gebruik hier die functie om code te schrijven die de string volledig naar hoofdletters omzet
// je code moet blijven werken zelfs als je een andere zin in de string zet
int main()
{
    char zin[] = "Sinterklaas komt bijna aan";
    for (int i = 0; i < strlen(zin); i++)
    {
        zin[i] = toupper(zin[i]);
    }
    printf("%s\n",zin);
}