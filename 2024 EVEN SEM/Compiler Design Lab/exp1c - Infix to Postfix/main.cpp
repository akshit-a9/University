#include <iostream>
#define max 50
using namespace std;

char stk[max], pstexp[max];
int top = -1;
char val;

void push(char ch) {
    top += 1;
    stk[top] = ch;
}

char pop() {
    val = stk[top];
    top -= 1;
    return val;
}

int main() {
    int n;
    cout << "Enter the no. of characters in the expression: ";
    cin >> n;
    char expr[n], ch;
    cout << "Enter the expression:" << endl;
    cin >> expr;
    cout << "The infix expression is:" << endl << expr << endl;
    for (int i = 0; i < n + 1; i++) {
        ch = expr[i];
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
            pstexp[i] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stk[top] != '(') {
                pstexp[i] = pop();
            }
            pop();
        } else {
            if (ch == '+' && stk[top] == '*' || ch == '+' && stk[top] == '/' || ch == '+' && stk[top] == '+') {
                pstexp[i] = pop();
                push(ch);
            } else if (ch == '-' && stk[top] == '*' || ch == '-' && stk[top] == '/' || ch == '-' && stk[top] == '+' || ch == '-' && stk[top] == '-') {
                pstexp[i] = pop();
                push(ch);
            } else if (ch == '/' && stk[top] == '*' || ch == '/' && stk[top] == '/') {
                pstexp[i] = stk[top];
                push(ch);
            } else if (ch == '*' && stk[top] == '*') {
                pstexp[i] = stk[top];
                push(ch);
            } else {
                push(ch);
            }
        }
    }

    while (top != -1 && stk[top] != '(') {
        pstexp[n] = pop();
        n += 1;
    }

    cout << "your postfix expression is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << pstexp[i];
    }

    return 0;
}
