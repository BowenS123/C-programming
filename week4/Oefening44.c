/*
  Maak het spel hoger lager waarbij een random geheel getal tussen 0 en 100 gegenereerd wordt en de gebruiker dit getal moet raden. Schrijf de game logic in een aparte functie genaamd hogerLagerSpel() die je oproept vanuit de main. Het return type van de functie
  hogerLagerSpel() dient een integer te zijn die aangeeft hoeveel pogingen nodig waren om het getal te raden.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hogerLagerSpel();

int main(void)
{
    int pogingen = hogerLagerSpel();
    printf("U heeft het getal geraden in %d pogingen.\n", pogingen);
    return 0;
}

int hogerLagerSpel()
{
    int zoekgetal, gebruikerGetal, pogingen = 0;

    srand(time(NULL));
    zoekgetal = rand() % 101;

    while (1)
    {
        printf("Doe een gok naar het getal [0, 100]: ");
        (void)scanf("%d", &gebruikerGetal);

        if (gebruikerGetal < 0 || gebruikerGetal > 100)
        {
            printf("Getal buiten bereik! Probeer opnieuw.\n");
            continue;
        }

        pogingen++;

        if (gebruikerGetal > zoekgetal)
        {
            printf("Uw getal is te hoog!\n");
        }
        else if (gebruikerGetal < zoekgetal)
        {
            printf("Uw getal is te laag!\n");
        }
        else
        {
            printf("U heeft juist gegokt!\n");
            break;
        }
    }

    return pogingen;
}
