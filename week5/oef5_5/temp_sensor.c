#include "temp_sensor.h"

double GetTemp()
{
    int temp = rand() %10 + 15;
    int brandgevaar = rand() %10;
    if(brandgevaar==0)
    {
        return 100;
    }
    else
    {
        return temp;
    }
}