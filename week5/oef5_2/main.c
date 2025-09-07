/*
Er zijn veel slecht samengestelde headers in deze oefening. Maak aanpassingen zodat
de main print statements werken zoals verwacht.
tip: maak gebruik van #ifndef en #ifdef
*/
#include "header1.h"
int smallest = MIN(5,3);
#include "header2.h"
#include "header3.h"
#include "stdio.h"

int main()
{
    //self introduction of Steve Peters and his amazing math skills
    int age = 20;
    printf("my name is %s\n",NAME);
    printf("my lastname is %s\n",LASTNAME);
    printf("I am %d years old\n",age);
    age = age +1;
    printf("so after my birthday I am %d\n",age);
    printf("of %d and %d, %d is the smaller number\n",5,3,smallest);
    printf("and of %d and %d, %d is the smaller number\n",7,12,MIN(7,12));

}