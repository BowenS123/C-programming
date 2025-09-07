#include <stdio.h>
#include <time.h>
//schrijf code zodat de dag in datum een random waarde heeft (1-31)
int main()
{
    srand(time(NULL));
    int dag = rand() % 32;
    printf("dag: %d\n",dag);
    char datum[] = "11 januari 2024";

    if(dag>=10)
    {
        int digit = dag/10;
        datum[0] = digit + '0';
        datum[1] = (dag % 10) + '0';
    }
    else
    {
        datum[0] = ' ';
        datum[1] = dag + '0';
    }
    printf("%s\n",datum);
    return 0;
}