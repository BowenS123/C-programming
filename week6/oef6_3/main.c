#include <stdio.h>
//schrijf code die het op een na grootste getal print samen met zijn index
int main()
{
    int array[] = {7,78,9,5,45,6,12};
    int grootste = array[0];
    int tweede = 0;
    
    for(int i = 0; i < 7;i++)
    {
        if (grootste < array[i])
        {
            grootste = array[i];
        }
        else if (tweede < array[i])
        {
            tweede = array[i];
        }
    }
    printf("grootste: %d\n",grootste);
    printf("tweede: %d\n",tweede);
}