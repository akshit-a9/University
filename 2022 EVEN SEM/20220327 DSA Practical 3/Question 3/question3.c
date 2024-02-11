//Write a function that removes leading spaces from a given string.

#include <stdio.h>

char *removespaces(char *str)
{
    static char str1[99];
    int count = 0, j, k;

    while(str[count]==' ') count++;
    for(j=count, k=0; str[j]!='\0'; j++, k++)
    {
        str[k] = str [j];
        str[k] = '\0';
    }
    return str1;
}

int main()
{
    char str[99];
    scanf("%s", &str);
    char ptr;
    ptr = removespaces(str);
    printf("%s", ptr);
    return 0;
}