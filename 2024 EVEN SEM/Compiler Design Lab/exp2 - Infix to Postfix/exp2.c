// infix to postfix conversion of expression 
#include <stdio.h>
#define max 50

char stk[max],pstexp[max];
int top=-1;
char val;

void push(char ch){
    top+=1;
    stk[top]=ch;
}

char pop(){
    val=stk[top];
    top-=1;
    return val;
}

int main() {
    int n;
    printf("Enter the no. of characters in the expression: ");
    scanf("%d", &n);
    char expr[n], ch;
    printf("Enter the expression:\n");
    scanf("%s",&expr);
    printf("The infix expression is:\n%s\n", expr);
    for(int i =0; i<n+1; i++){
        ch=expr[i];
        printf("stk: %c\n", stk[top]);
        printf("stk-1: %c\n", stk[top-1]);
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
            pstexp[i]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(stk[top] != '('){
                pstexp[i]=pop();
            }
            pop();
        }
        else
        {
            printf("ope: %c\n", ch);
            if(ch=='+' && stk[top]=='*' || ch=='+' && stk[top]=='/' || ch=='+' && stk[top]=='+'){
                pstexp[i]=stk[top];
                push(ch);
            }
            else if(ch=='-' && stk[top]=='*' || ch=='-' && stk[top]=='/' || ch=='-' && stk[top]=='+' || ch=='-' && stk[top]=='-'){
                pstexp[i]=pop();
                push(ch);
            }
            else if(ch=='/' && stk[top]=='*' || ch=='/' && stk[top]=='/'){
                pstexp[i]=stk[top];
                push(ch);
            }
            else if(ch=='*' && stk[top]=='*'){
                pstexp[i]=stk[top];
                push(ch);
            }
            else{
                push(ch);
            }
        }
    }

    while(top!=-1 && stk[top]!='('){
        pstexp[n]=pop();
        n+=1;
    }

    printf("your postfix expression is:\n");
    for(int i=0; i<n; i++){
        printf("%c",pstexp[i]);
    }
   
    return 0;
}