/*
  Maak een hoger – lager spel

  De gebruiker wordt het volgende gevraagd:
  Doe een gok naar het getal [1, 100]:
  Indien het getal te hoog is:
  Uw getal is te hoog!
  Indien het getal te laag is:
  Uw getal is te laag!
  De gebruiker mag dan opnieuw proberen
  Indien het getal juist is:
  U heeft juist gegokt in x pogingen.
  Indien de gebruiker een getal buiten het interval [1,100]
  ingeeft moet het programma geen poging bijtellen en opnieuw de vraag stellen.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
	int zoekgetal = 0;

	/** deze code maakt een "random getal" |
	in het interval [1, 100] */
	srand( time( NULL ) );
	zoekgetal = rand() % 100 + 1;
	// zoekgetal heeft nu een random waarde
	// in het interval [1, 100]
	int gebruikerGetal = 0;
	int pogingen = 0;

	// TODO : oneindige loop voor elke gok
	while(1)
	{
		printf( "Doe een gok naar het getal [1, 100]: " );
		(void)scanf( "%d", &gebruikerGetal );

		// TODO : gebruik continue wanneer de gebruiker een getal ingeeft dat niet binnen de range valt
		if(gebruikerGetal < 1 || gebruikerGetal > 100)
		{
			printf("Getal buiten bereik! Probeer opnieuw.\n");
			continue;
		}

		// TODO : hou aantal pogingen bij
		pogingen++;
		
		// TODO : geef weer indien het hoger of lager ligt
		if (gebruikerGetal > zoekgetal)
		{
            printf("Uw getal is te hoog!\n");
        }
		else if (gebruikerGetal < zoekgetal)
		{
            printf("Uw getal is te laag!\n");
        }
		else
		// TODO : gebruik break wanneer het getal is geraden
		{
            printf("U heeft juist gegokt in %d pogingen.\n", pogingen);
            break;
        }
	}
	return 0;
}
