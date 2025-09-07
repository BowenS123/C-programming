#include "temp_sensor.h"

double getTemp()
{
    int temp = rand() %10 + 15;
    int brandgevaar = rand() %10; //temp van 15 tot 25 (25 niet inbegrepen)
    if(brandgevaar==0) //1/10 kans voor brand
    {
        return 100;
    }
    else
    {
        return temp;
    }
}