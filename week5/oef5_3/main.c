/*
de macros in de header file maken de code hier veel korter maar sommigen werken niet. 
pas de headerfile aan zodat alle macros werken. Gebruik geen functies in deze oefening
en pas main.c niet aan.
*/
#include "macros.h"
#include "stdio.h"
int main()
{
    int a = 3;
    int b = 5;
    printf("de square van a is: %d\n",SQUARE(a));
    printf("de square van a+b is: %d\n",SQUARE(a+b));
    printf("de sum van a+b is: %d\n",SUM(a,b));
    printf("3 keer de sum is :%d\n",3 * SUM(a,b));
    printf("print lucky number 7: %d\n",NUMBER);
}