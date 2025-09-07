/*
  Maak een functie genaamd printHelloWorld() die 'Hello world!' print. Roep deze functie 10x op vanuit de main doormiddel van een for-loop.
*/
#include <stdio.h>

void printHelloWorld();

int main(void)
{
  for(int i = 0; i < 10; i++)
  {
    printHelloWorld();
  }
  return 0;
}

void printHelloWorld()
{
  printf("Hello World!\n");
}