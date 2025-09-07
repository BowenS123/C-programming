/*
  Voer onderstaande code uit en corigeer.
    1. Wat verwacht je dat er geprint wordt?
	Men zou kunnen verwachten dat de output "i is NIET 8 !!!\n" is omdat i oorspronkelijk 9 is en de voorwaarde lijkt te controleren of i gelijk is aan 8.
    2. Wat wordt er geprint?
	De werkelijke output is "i is 8 !!!\n".
    3. Wat is de oorzaak?
	De oorzaak is dat in de voorwaarde if (i = 8), de enkele gelijkteken = een toewijzingsoperator is, en geen vergelijking. Hierdoor wordt i de waarde 8 toegekend en het resultaat van de toewijzing is true (want elke niet-nul waarde wordt als waar beschouwd).
    4. Corrigeer de code
	Om dit te corrigeren, moet de toewijzingsoperator = vervangen worden door de gelijkheidoperator ==, die gebruikt wordt voor vergelijking. Hier is de gecorrigeerde versie van de code:
*/

#include <stdio.h>

int main( void )
{
	int i = 9;
	if( i == 8 )
	{
		printf( "i is 8 !!!\n" );
	}
	else
	{
		printf( "i is NIET 8 !!!\n" );
	}

	return 0;
}
