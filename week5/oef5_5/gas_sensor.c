//de gas sensor returned "normaal" "rook" of "gif", weergegeven als 0,1,2
//de waarschijnlijkheid hangt af van de settings
#include "gas_sensor.h"
int Getgas()
{
    int kans = rand() %101;
    if(kans < GASRISK)
    {
        if (kans <= GASRISK / 2)
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