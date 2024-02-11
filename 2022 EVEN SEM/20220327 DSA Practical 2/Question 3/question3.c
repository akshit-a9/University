//Write a recursive function that convert a string of numerals to an integer.
//P.S. - Needs to be checked over. 

#include <stdio.h>
#include <ctype.h>

void conv(char *s, int *pnum)
{
    if(*s = '\0' || ! isdigit(*s)) return;
    *pnum =(*pnum)*10 + *s - '0';
    return conv(s+1, pnum);
}

int main()
{
    char str[150];
    int num;
    gets(str);
    conv(str, &num);
    printf("Converted number is : %d", num);

    return 0;
}