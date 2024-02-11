//Write a recursive function that removes all the occurrences of a specified character in a string.

#include <stdio.h>
#include <string.h>

void delchar(char *s, char c)
{
    static int i=0, k=0;
    if(!s[i]) return;
    else 
    {
        s[i] = s[i+k];
        if(s[i] == c)
        {
            k++;
            i--;
        }
        i++;
        delchar(s,c);
    }
}

int main()
{
    char s[150], c;
    gets(s);
    c = getchar();
    delchar(s, c);

    printf("%s", s);
    return 0;
}