/*
  Schrijf een programma dat de faculteit (!) berekent van een positief geheel getal ingegeven door de gebruiker. Maak gebruik van een FOR-Loop. Zorg er ook voor dat er eerst gecontroleerd wordt of n een getal > 1. Gebruik voor het resultaat van de
  berekening een long unsigned int type. Controleer telkens voor je het nieuwe resultaat berekent of je long unsigned int niet overflowed, maak hiervoor gebruik van de constante:

  ULONG_MAX uit <limits.h>.

  Faculteit is een wiskundige operatie:  6! = 6*5*4*3*2*1
  Of algemeen:                           n! = n*(n-1)*(n-2)*(n-3)*(n-4) …
*/
#include <stdio.h>
#include <limits.h>

int main( void )
{
	int geheelGetal = 0;
	long unsigned int resultaat = 1;
	
	// TODO : doe minstens 1 keer
	// TODO : en herhaal zolang geheelGetal <= 1
    do
    {
        printf( "Geef een geheel getal groter dan 1 in: " );
        (void)scanf( "%d", &geheelGetal );
    } while( geheelGetal <= 1 );

	// HINT : zolang ( ULONG_MAX / resultaat ) >= het getal dat je erbij wil vermenigvuldigen, zal de vermeningvuldiging niet overflowen. Bij ( (uint64_t)n > ULONG_MAX / resultaat ) --> printf( "Faculteit te groot om te berekenen!\n" ) en break
	for (int i = 1; i <= geheelGetal; i++) 
    {
        if ((ULONG_MAX / resultaat) >= (long unsigned int)i)
        {
            resultaat *= i;
        }
        else
        {
            printf( "Faculteit te groot om te berekenen!\n" );
            return 1;
        }
    }

	printf( "De faculteit van %d = %d\n", geheelGetal, resultaat );

	return 0;
}
