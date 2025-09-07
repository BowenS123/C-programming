/*
  Zorg dat het programma stopt na 10 pogingen of wanneer 21 werd ingegeven…
*/

#include <stdio.h>

int main( void )
{
	int n = 0;
	int pogingen = 0;

	while( pogingen < 10 && n != 21 )
	{
		printf( "Geef een getal in: " );
		(void)scanf( "%d", &n );
		printf( "U gaf getal: %d in\n", n );
		pogingen++;
	}
	printf( "\n" );
	return 0;
}
