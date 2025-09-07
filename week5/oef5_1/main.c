#include <stdio.h>
#include "math_utils.h"

void main() 
{
    int getal1, getal2;
    scanf("%d %d", &getal1, &getal2);   

    printf("Het grootste getal is: %d\n", MAX(getal1, getal2));
    printf("Het kwadraat van het grootste getal is: %d\n", square(MAX(getal1, getal2)));
    return;
}