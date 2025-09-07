#include <stdio.h>
#include <string.h>
/*
laat de gebruiker een zin schrijven. test voor elk woord of
het een palindroom is (gespiegeld hetzelfde woord, bv negen)
print hoeveel palindromen er in de zin steken en welke
*/
int palindroom(char*str1);
int main()
{
    char woord[50];
    char zin[200];
    int aantal = 0;
    printf("Schrijf een zin: ");
    fgets(zin, sizeof(zin), stdin);
    zin[strcspn(zin, "\n")] = 0;

    char *token = strtok(zin, " ");
    while (token != NULL)
    {
        if (palindroom(token) == 0)
        {
            printf("%s\n", token);
            aantal++;
        }
        token = strtok(NULL, " ");
    }

    printf("Aantal palindromen: %d\n", aantal);
    return 0;
}

int palindroom(char*str1)
{
    for (int i = 0;i<strlen(str1);i++)
    {
        if (str1[i]!=str1[strlen(str1)-i-1])
        {
            return 1;
        }
        
    }
    return 0;
}