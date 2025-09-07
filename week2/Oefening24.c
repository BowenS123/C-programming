/*
  Schrijf een programma dat een plaats vraagt aan de gebruiker en bepaald welke prijs overeenkomt met de ingegeven plaats.

   Plaats    Prijs
  ================
    1        1000
    2         250
    3         100
    4          50
    5          50
    > 5         0

  Maak hierbij gebruik van de conditionele operator (? :).
*/

#include <stdio.h>

int main( void )
{
	int plaats = 0;
	int prijs = 0;

	printf( "Geef een plaats in: " );
	(void)scanf( "%d", &plaats );

   prijs = (plaats == 1) ? 1000 :
           (plaats == 2) ? 250  :
           (plaats == 3) ? 100  :
           (plaats >= 4 && plaats <= 5) ? 50 : 0;

	printf( "De prijs voor plaats %d = %d\n", plaats, prijs );

	return 0;
}
