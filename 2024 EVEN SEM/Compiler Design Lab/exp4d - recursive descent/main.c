//recursive descent parser for the grammar 
//E->iT/F
//T->+iT/#
//F->*jF/#

/* and for any equation of addition and multiplication*/

#include <stdio.h>  
#include <ctype.h> 

int E(), T(), F();

const char * cursor;
char string[64];

int isInteger() {
    if (isdigit(*cursor)) {
        while (isdigit(*cursor)) {
            cursor++;
        }
        return 1;
    }
    return 0;
}

int main() {
   
    puts("Enter the string");  
    scanf("%s", string);  
    cursor = string;
   
   
    if(E()){
        printf("String Accepted ");
    }
    else printf("String Not Accepted ");
    return 0;
}

int E(){
   
    if(isInteger()){
        return T();
    }
   
    return 0;
}

int T()
{
    if(*cursor=='+'){
        cursor++;
        if(isInteger()){
            return T();
        }
    }
   
    if(*cursor=='\0'){
        return 1;
    }
   
    return 0;
}

int F()
{
    if(*cursor=='*'){
        cursor++;
        if(isInteger()){
            return F();
        }
    }
   
    if(*cursor=='\0'){
        return 1;
    }
   
    return 0;
}
