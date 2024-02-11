#include <stdio.h>
int main()
{
    int num, i = 0;
    printf (" Enter a number to generate the table in C: ");
    scanf (" %d", &num);

    printf ("\n Table of %d", num);
    Multiply_tab (num, 1);
}

void Multiply_tab (int num, int i)
{
    printf (" \n");
    printf (" %d x %d = %d ", num, i, (num * i));

    if (i < 10)
        return Multiply_tab (num, i + 1);
}
