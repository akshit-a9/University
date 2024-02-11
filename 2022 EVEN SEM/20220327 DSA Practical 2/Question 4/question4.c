//Write a recursive function that changes an integer to a binary number.

#include <stdio.h>

int conv(int a)
{
    if(a==0) return 0;
    else return(a%2 + 10*conv(a/2));
}

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", conv(a));
    return 0;
}