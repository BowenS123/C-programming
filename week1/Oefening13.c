/*
  Schrijf een programma dat de deling van 2 gehele getallen, die door de gebruiker worden ingegeven, berekent en het resultaat print.
*/
#include <stdio.h>

int main( void )
{
	int getal1 = 0;
	int getal2 = 0;
	int result = 0;

	printf( "Geef 2 gehele getallen in: " );
	result = scanf( "%d %d", &getal1, &getal2 );

	printf( "%d / %d = %.2f\n", getal1, getal2, (float)getal1 / getal2/*deling van getal 1 en getal 2*/ );

	return 0;
}
