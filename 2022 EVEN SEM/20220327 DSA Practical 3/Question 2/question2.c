//Program to check if a matrix is symmetric

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3][3], i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        scanf("%d", &arr[i][j]);
    }

    int s = 1;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(arr[i][j] != arr[j][i])
            {
                s=0;
                break;
            }    
        }
    }
    printf("%d", s);
    return 0;
}