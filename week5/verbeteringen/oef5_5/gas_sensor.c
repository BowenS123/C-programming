//de gas sensor returned "normaal" "rook" of "gif", weergegeven als 0,1,2
//de waarschijnlijkheid hangt af van de settings
#include "gas_sensor.h"
int GetGas()
{
    /*
    Ik heb GASRISK als een procentuele kans dat er iets mis gaat beschouwd en als er iets mis is, 
    is het een 50/50 voor rook of gif. Elke andere oplossing waarbij de kansen afhangen van GASRISK zijn 
    ook juist.
    */
    int kans = rand() % 100+1;
    if(kans<GASRISK)
    {
        if(kans<=GASRISK/2)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 0;
    }
}