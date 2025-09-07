//Pas deze code aan om het te doen werken.
//maak een degelijke structuur van header- en sourcefiles. De print output moet ook netjes zijn

/* 
Een gebouw heeft een reeks sensoren ter beveiliging. De hoofdcentrale moet alle metingen van de sensoren netjes printen.
temp wordt in graden clecius geprint, inbraak met woorden (bv "Veilig" en "INBRAAK!") en gas met woorden 
Als de metingen gevaarlijk zijn moet het alarm ook afgaan (ook weergegeven door te printen)
*/

/*
Hier is een voorbeeld van hoe je een random getal tussen 10 en 20 krijgt (20 niet inbegrepen)
#include <time.h>
#include <stdlib.h>
srand(time(NULL));
double number = (rand() %10)+10
*/
#include <stdio.h>
#include "settings.h"
#include "laser_alarm.h"
#include "gas_sensor.h"
#include "temp_sensor.h"
/*
we passen onze printer aan zodat die de pointer van fopen meegeeft
*/
void printer(FILE * pointer); 
int main()
{
    FILE * fpointer = fopen("text.txt","a"); //file openen en pointer opslaan
    srand(time(NULL));
    fprintf(fpointer,"\n\n"); //pointer altijd meegeven voor fprintf
    fprintf(fpointer,"***Sensoren overzicht %s***\n",NAME);
    fprintf(fpointer,"temp\tinbraak\tgas\n");
    for (int i=0;i<LIMIT;i++){
        printer(fpointer);
    }

    fclose(fpointer); //op het einde van ons programma moeten we ons bestand nog sluiten
}

void printer(FILE * pointer)
{
    //print 1 lijn met alle waarden van de sensoren op dat moment.
    //print ook waarschuwingen wanneer nodig.
    int temp = getTemp();
    int gas = GetGas();
    int inbraak = GetDetection();

    //Voor het volgende stuk gaan we later nog veel betere manieren zijn.
    //Voor nu gebruiken we enkel if/else 
    if(inbraak==0)
    {
        if(gas==0)
        {
            fprintf(pointer,"%d\t%s\t%s\n",temp,"veilig","normaal");
        }
        else if(gas==1)
        {
            fprintf(pointer,"%d\t%s\t%s\n",temp,"veilig","rook");
            fprintf(pointer,"ROOKALARM !!!\n");
        }
        else
        {
            fprintf(pointer,"%d\t%s\t%s\n",temp,"veilig","gif");
            fprintf(pointer,"GIFGAS ALARM !!!\n");
        }
    }
    else
    {
        if(gas==0)
        {
            fprintf(pointer,"%d\t%s\t%s\n",temp,"INBRAAK","normaal");
        }
        else if(gas==1)
        {
            fprintf(pointer,"%d\t%s\t%s\n",temp,"INBRAAK","rook");
            fprintf(pointer,"ROOKALARM !!!\n");
        }
        else
        {
            fprintf(pointer,"%d\t%s\t%s\n",temp,"INBRAAK","gif");
            fprintf(pointer,"GIFGAS ALARM !!!\n");
        }
        fprintf(pointer,"EEN INBREKER\n");
    }
    if(temp>=100)
    {
        fprintf(pointer,"BRAND!\n");
    }

}