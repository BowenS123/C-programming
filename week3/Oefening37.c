/*
    Volgende code zou PXL in grote letters verticaal printen, maar het gaat mis.
*/

#include <stdio.h>

int main( void )
{
    int i = 0;
	int j = 0;

    while (i < 2)
    {
        j = 0;
        while (j < 24)
        {
            printf("P");
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 8)
        {
            printf("P");
            j++;
        }
        j = 0;
        while (j < 8)
        {
            printf(" ");
            j++;
        }
        j = 0;
        while (j < 8)
        {
            printf("P");
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 2)
    {
        j = 0;
        while (j < 24)
        {
            printf("P");
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 6)
    {
        j = 0;
        while (j < 8)
        {
            printf("P");
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 4)
    {
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 8)
        {
            printf("X");
            j++;
        }
        j = 0;
        while (j < 8)
        {
            printf(" ");
            j++;
        }
        j = 0;
        while (j < 8)
        {
            printf("X");
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 8)
        {
            printf(" ");
            j++;
        }
        j = 0;
        while (j < 8)
        {
            printf("X");
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 8)
        {
            printf("X");
            j++;
        }
        j = 0;
        while (j < 8)
        {
            printf(" ");
            j++;
        }
        j = 0;
        while (j < 8)
        {
            printf("X");
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 4)
    {
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 12)
    {
        j = 0;
        while (j < 8)
        {
            printf("L");
            j++;
        }
        printf("\n");
        i++;
    }

    i = 0;
    while (i < 2)
    {
        j = 0;
        while (j < 24)
        {
            printf("L");
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}

