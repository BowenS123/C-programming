#include "laser_alarm.h"

int GetDetection()
{
    int kans = rand() %6;
    if(kans==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
