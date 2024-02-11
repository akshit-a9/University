#include<stdio.h>
int sum(int num);
int rec_sum(int num);
void main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    printf("\nSum of first %d numbers is: %d",n, rec_sum(n));
}
// This function is for non recursion
int sum(int num)
{
    int res=0;
    while(num) //we can write this condition as while(num!=0) both are same
    {
        res = res + num;
        num = num-1;
    }
    return res;
}
//This function is for recursion. 
int rec_sum(int num)
{
    while(num)
    {
        return (num+sum(num-1));
    }
}
