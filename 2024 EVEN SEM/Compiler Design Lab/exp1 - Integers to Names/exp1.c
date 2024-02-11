#include <stdio.h>
#include <stdlib.h>

int main()

{
    int num,mod,z,x,a=0;

    printf("Enter a number, with a maximum of 3 digits.\n");
    scanf("%d",&num);

    if(num >= 0 && num <= 999)
    {
    x=num;
    while(x!=0)
    {
        z=x%10;
        a=a*10+z;
        x/=10;
    }

    while(a!=0)
    {
        mod=a%10;
         switch (mod) {
            case 0:
              printf("ZERO ");
              break;
            case 1:
              printf("ONE ");
              break;
            case 2:
              printf("TWO ");
              break;
            case 3:
              printf("THREE ");
              break;
            case 4:
              printf("FOUR ");
              break;
            case 5:
              printf("FIVE ");
              break;
            case 6:
              printf("SIX ");
              break;
            case 7:
              printf("SEVEN ");
              break;
            case 8:
              printf("EIGHT ");
              break;
            case 9:
              printf("NINE ");
              break;};

        a/=10;
    }
    }
    else
    {
    printf("Error! The entered number is out of range!");
    }

    return 0;
}