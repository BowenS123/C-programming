/*
  Pi kan benaderd worden door de volgende formule:

  PI = 4x(1-(1/3)+(1/5)-(1/7)+(1/9)-(1/11)+(1/13)-...)

  Schrijf een programma dat deze benadering uitrekent met instelbare lengte for-lus/while counting-lus.
  Bereken ook het verschil tussen uw benadering en het getal PI uit de math.h library van c (M_PI) en print deze uit.
*/

#include <stdio.h>
#include <math.h>
#include <corecrt_math_defines.h>

int main( void )
{
	double pi = 0;
	int lengtePiBerekening = 0;
	printf( "Geef de lengte van de gewenste PI berekening: " );
	(void)scanf( "%d", &lengtePiBerekening );

	// HINT : maak gebruik van conditional operator voor de +/-
	for (int i = 0; i < lengtePiBerekening ; i++)
	{
		pi += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
	}
	pi *= 4;

	printf( "PI = %f\n", pi );
	printf( "M_PI - PI = %f\n", (M_PI) - pi );

	return 0;
}
