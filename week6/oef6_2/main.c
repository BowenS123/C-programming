#include <stdio.h>
//voeg code toe zodat de tweede array de omgekeerde inhoud van de eerste heeft
//Dus het moet 7,6,5,4,3,2,1 zijn, print dit ook
int main()
{
    int firstArray[] = {1,2,3,4,5,6,7};
    int secondArray[7];

    for(int i = 0; i < 7;i++)
    {
        secondArray[i] = firstArray[7-i-1];
        printf("index %d getal %d\n",i,secondArray[i]);
    }
}