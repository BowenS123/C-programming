#include "laser_alarm.h"
int GetDetection()
{
    int kans = rand() %5 +1; //geeft een 1/5 kans op 1
    if(kans==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}