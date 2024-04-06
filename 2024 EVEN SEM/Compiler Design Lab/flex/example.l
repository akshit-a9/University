%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent variables and their values
typedef struct {
    char name[20];
    int value;
} Variable;

Variable variables[20]; // Array to store variables and their values
int varCount = 0; // Variable count

void addOrUpdateVariable(char* name, int value) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value = value;
            return;
        }
    }
    strcpy(variables[varCount].name, name);
    variables[varCount].value = value;
    varCount++;
}

int getVariableValue(char* name) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    return 0; // Default value if variable not found
}
%}

%option noyywrap

%%

[a-zA-Z][a-zA-Z0-9]*  {
                        printf("IDENTIFIER: %s\n", yytext);
                        addOrUpdateVariable(yytext, getVariableValue(yytext) + 1); // Perform postfix increment
                      }
"++"                   {
                        printf("INCREMENT\n");
                        addOrUpdateVariable(yytext - 1, getVariableValue(yytext - 1) + 1); // Perform postfix increment
                      }
"--"                   {
                        printf("DECREMENT\n");
                        addOrUpdateVariable(yytext - 1, getVariableValue(yytext - 1) - 1); // Perform postfix decrement
                      }
[()]                   {
                        printf("PARENTHESIS: %c\n", yytext[0]);
                      }
[+]                    {
                        printf("ADD\n");
                      }
[ \t\n]                ; /* Ignore whitespace and newline */

.                      {
                        printf("Invalid character: %c\n", yytext[0]);
                      }

%%

int main() {
    printf("Enter postfix expression: ");
    yylex();
    printf("Variables after postfix operations:\n");
    for (int i = 0; i < varCount; i++) {
        printf("%s = %d\n", variables[i].name, variables[i].value);
    }
    return 0;
}
