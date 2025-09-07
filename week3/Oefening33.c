/*
  Maak een programma dat het volgende print:

  0
  0 1
  0 1 2
  0 1 2 3
  0 1 2 3 4
  0 1 2 3 4 5
  0 1 2 3 4 5 6
  0 1 2 3 4 5 6 7
  0 1 2 3 4 5 6 7 8
  0 1 2 3 4 5 6 7 8 9
  0 1 2 3 4 5 6 7 8
  0 1 2 3 4 5 6 7
  0 1 2 3 4 5 6
  0 1 2 3 4 5
  0 1 2 3 4
  0 1 2 3
  0 1 2
  0 1
  0
*/

#include <stdio.h>

int main( void )
{
	int max = 1;
	int number = 0;
	int breedte = 6;
	printf( "geef breedte van de vlag in\n" ); // optioneel
	(void)scanf( "%d", &breedte );             // optioneel

	// TODO : loop voor oplopende kant met een loop in die alle nummers afgaat
  for(int i = 0; i <= breedte; i++)
  {
    for( int j = 0; j <= i; j++)
    {
      printf(" %d ", j);
    }
    printf("\n");
  }
	// TODO : loop voor aflopende kant met een loop in die alle nummers afgaat
  for(int i = breedte - 1; i >= 0; i--)
  {
    for( int j = 0; j <= i; j++)
    {
      printf(" %d ", j);
    }
    printf("\n");
  }
	return 0;
}
