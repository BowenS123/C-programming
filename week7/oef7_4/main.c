#include <stdio.h>
#include <string.h>
/*
schrijf code die de gebruiker twee zinnen laat invullen.
print vervolgens of beide zinnen identiek zijn in dit formaat(met tremas):
De zin "str1" is (niet) gelijk aan "str2".
*/
int main()
{
    char zin1[50];
    char zin2[50];
    char tot[200];
    printf("zin1: ");
    fgets(zin1,sizeof(zin1),stdin);
    printf("zin2: ");
    fgets(zin2,sizeof(zin2),stdin);
    strcpy(tot,"De zin \'");
    strcat(tot,zin1);
    if(strcmp(zin1,zin2)==0)
    {
    strcat(tot,"\' is gelijk aan \'");
    }
    else
    {
    strcat(tot,"\' is niet gelijk aan \'");
    }
    strcat(tot,zin2);
    strcat(tot,"\'");
    printf("%s\n",tot);
    return 0;
}