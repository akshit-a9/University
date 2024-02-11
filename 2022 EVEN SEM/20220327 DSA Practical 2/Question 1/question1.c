//Write a recursive function to find out the reverse of a string using pointers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rev (char *x, int start, int end)
{
    char ch;
    if(start>=end) return;
    ch = *(x+start);
    *(x+start) = *(x+end);
    *(x+end) = ch;
    rev(x, ++start, --end);
}

int main()
{
    char strarr[150];
    printf("Enter a string : ");
    scanf("%s", strarr);

    rev(strarr, 0, strlen(strarr)-1);
    printf("\n Reversed string is: %s", strarr);

    return 0;
}