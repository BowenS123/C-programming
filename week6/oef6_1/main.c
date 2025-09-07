#include <stdio.h>
//schrijf een loop die het totaal van de array print

//schrijf daarna een loop die de hoogste en laagste waarde print
int main()
{
    int array[] = {5,4,7,9,5,77};
    int totaal = 0;
    int hoogste = array[0];
    int laagste = array[0];

    for(int i = 0;i < 6;i++)
    {
        totaal += array[i];
    }
    
    for(int j = 0; j < 6;j++)
    {
        if(hoogste < array[j])
        {
            hoogste = array[j];
        }
        if(laagste > array[j])
        {
            laagste = array[j];
        }
    }
    printf("totaal: %d\n",totaal);
    printf("hoogste: %d\n",hoogste);
    printf("laagste: %d\n",laagste);
    return 0;
}