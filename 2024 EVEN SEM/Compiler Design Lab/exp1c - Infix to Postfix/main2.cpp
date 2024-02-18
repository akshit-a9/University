#include <iostream>
#define max 50
using namespace std;

char stk[max], pstexp[max];
int top = -1;

void push(char ch) {
    top += 1;
    stk[top] = ch;
}

char pop() {
    char val = stk[top];
    top -= 1;
    return val;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main() {
    int n;
    cout << "Enter the no. of characters in the expression: ";
    cin >> n;
    char expr[n], ch;
    cout << "Enter the expression:" << endl;
    cin >> expr;
    cout << "The infix expression is:" << endl << expr << endl;

    int k = 0; 

    for (int i = 0; i < n; i++) {
        ch = expr[i];
        if (isalnum(ch)) {
            pstexp[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stk[top] != '(') {
                pstexp[k++] = pop();
            }
            if (top != -1 && stk[top] == '(')
                pop(); 
        } else { 
            while (top != -1 && precedence(stk[top]) >= precedence(ch)) {
                pstexp[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        pstexp[k++] = pop();
    }

    pstexp[k] = '\0'; 

    cout << "Your postfix expression is:" << endl;
    cout << pstexp << endl;

    return 0;
}
