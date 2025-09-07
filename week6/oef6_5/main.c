/*
transponeer deze matrix: dat wil zeggen,
zorg dat de rijen kolommen worden en de kolommen rijen

de uitkomst zou er zo moeten uitzien:
1 4 7
2 5 8
3 6 9
*/
#include <stdio.h>
int main()
{
    int Array[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int nArray[3][3];
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            nArray[i][j] = Array[j][i];
            printf("%d\t",nArray[i][j]);
        }
        printf("\n\n");
    }
}