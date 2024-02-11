//Write a recursive function to determine whether a string is palindrome, Capitalization and spacing are ignored.

#include <stdio.h>
#include <string.h>

void rev(char *x, int start, int end)
{
    char ch;
    if(start >= end) return;

    ch= *(x+start);
    *(x+start) = *(x+end);
    *(x+end) = ch;
    rev(x, ++start, --end);
}

int check (const char *strarr, const char *cpyarr)
{
    return strcmp(strarr, cpyarr);
}

int main()
{
    char strarr[150], cpyarr[150];
    scanf("%s", &strarr);
    strcpy(cpyarr, strarr);
    rev(strarr, 0, strlen(strarr)-1);

    int ans = check(strarr, cpyarr);
    if(ans==0) printf("Palindrome");
    else printf("Not a palindrome.");

    return 0;
}