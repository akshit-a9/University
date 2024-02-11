/*#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>

int main()
{     
    printf("Files in Directory are:n");
    system("who");
}*/

#include <stdio.h>
#include <unistd.h>
int main() {
    printf("The files in the directory are:\n");
    system(" dir \n");
    return 0;
}
