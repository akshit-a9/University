//Odd Zeros, Odd Ones

#include <stdio.h>
#include <string.h>

int main() {

    int n;
    char state='a';
    printf("Enter the size of string: ");
    scanf("%d",&n);
    int string[n];
    printf("Enter the string of 0 & 1:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&string[i]);
    }
    printf("The string input is : ");
    for(int i=0; i<n; i++)
    {
        printf("%d",string[i]);
    }

    for(int i=0; i<n; i++)
    {
        if (state=='a'&& string[i]==0){
            state='c';
        }
        else if (state=='a' && string[i]==1){
            state='b';
        }
        else if (state=='b' && string[i]==0){
            state='d';
        }
        else if (state=='b' && string[i]==1){
            state='a';
        }
        else if (state=='c' && string[i]==0){
            state='a';
        }
        else if (state=='c' && string[i]==1){
            state='d';
        }
        else if (state=='d' && string[i]==0){
            state='b';
        }
        else if (state=='d' && string[i]==1){
            state='c';
        }
    }
    if (state=='d')
    {
        printf("\nThe string is accepted by the DFA");
    }
    else
    {
        printf("\nThe string is not accepted by the DFA");
    }
    return 0;
}