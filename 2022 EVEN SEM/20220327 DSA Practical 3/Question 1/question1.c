//Program to find the saddle point of a 3x3 matrix

#include <stdio.h>
#include <stdlib.h>

int saddlepoint(int arr[3][3])
{
    int i, j, k, c, min;
    for(i=0; i<3; i++)
    {
        min = arr[i][0], c=0;
        for(j=0; j<3; j++)
        {
            if(min > arr[i][j])
            c=j;
        }
    }

    for(k=0; k<3; k++)
    {
        if(min < arr[k][c]) break;
    }

    if(k==3) return min;
    else return -1;
}

int main()
{
    int arr[3][3], j, i;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        scanf("%d", &arr[i][j]);
    }
    
    printf("\nSaddle Point of matrix : %d", saddlepoint(arr));

    return 0;
}