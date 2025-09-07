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
doordat main geen .h heeft maar wel een functie buiten main()
herkent de compiler de printer() functie niet zonder volgende lijn
alternatief kan je ook main() onder printer() zetten. Dit was niet 
opzettelijk en zal niet meer voorkomen.
*/
void printer(); 
int main()
{
    /*
    dit is iets dat makkelijk fout gaat: je moet maar 1 keer srand oproepen,
    als je srand binnen bv getgas zet words het elke loop opnieuw opgeroepen
    waardoor je dezelfde uitkomsten blijft krijgen.
    */
    srand(time(NULL)); 
    printf("***Sensoren overzicht %s***\n",NAME);
    printf("temp\tinbraak\tgas\n");
    for (int i=0;i<LIMIT;i++){
        printer();
    }
}

void printer()
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
            printf("%d\t%s\t%s\n",temp,"veilig","normaal");
        }
        else if(gas==1)
        {
            printf("%d\t%s\t%s\n",temp,"veilig","rook");
            printf("ROOKALARM !!!\n");
        }
        else
        {
            printf("%d\t%s\t%s\n",temp,"veilig","gif");
            printf("GIFGAS ALARM !!!\n");
        }
    }
    else
    {
        if(gas==0)
        {
            printf("%d\t%s\t%s\n",temp,"INBRAAK","normaal");
        }
        else if(gas==1)
        {
            printf("%d\t%s\t%s\n",temp,"INBRAAK","rook");
            printf("ROOKALARM !!!\n");
        }
        else
        {
            printf("%d\t%s\t%s\n",temp,"INBRAAK","gif");
            printf("GIFGAS ALARM !!!\n");
        }
        printf("EEN INBREKER\n");
    }
    if(temp>=100)
    {
        printf("BRAND!\n");
    }

}