#include <stdio.h>
#include "math_utils.h"
int main()
{
    int getal1;
    int getal2;
    printf("geef een eerste getal: ");
    scanf("%d",&getal1);
    printf("geef een tweede getal: ");
    scanf("%d",&getal2);
    int grootste = MAX(getal1,getal2);
    printf("uitkomst: %d",square(grootste));
}