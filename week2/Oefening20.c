/*
  Evalueer onderstaande logische uitdrukkingen. Indien de uitdrukking waar is print je TRUE. Indien de uitdrukking niet waar is print je FALSE. Maak gebruik van de conditionele operator (? :).
  Een underscore "_" indiceert iets dat nog ingevuld moet worden.
*/

#include <stdio.h>

int main( void )
{
	float x = 15.0;
	float y = 25.0;

	printf( "x != y \t\t\t-> %s\n", /*_*/ (x != y) ? "TRUE" : "FALSE");
	printf( "x < x \t\t\t-> %s\n", /*_*/ (x < x) ? "TRUE" : "FALSE");
	printf( "x >= y - x \t\t-> %s\n", /*_*/ (x >= y - x) ? "TRUE" : "FALSE");
	printf( "x == y + x - y \t-> %s", /*_*/ (x == y + x - y) ? "TRUE" : "FALSE" );

	return 0;
}
