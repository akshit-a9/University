%{
#include <stdio.h>
int operators_count = 0, operands_count = 0, valid = 1, depth = 0;
%}

%%

"(" { depth++; printf("%s is an opening bracket\n", yytext); }
")" { if(depth > 0) depth--; else valid = 0; printf("%s is a closing bracket\n", yytext); }

"{" { depth++; printf("%s is an opening brace\n", yytext); }
"}" { if(depth > 0) depth--; else valid = 0; printf("%s is a closing brace\n", yytext); }

"[" { depth++; printf("%s is an opening square bracket\n", yytext); }
"]" { if(depth > 0) depth--; else valid = 0; printf("%s is a closing square bracket\n", yytext); }

"++"|"--" { 
    operators_count++; 
    printf("%s is a unary operator\n", yytext);
}

"+"|"-"|"*"|"/" { operators_count++; printf("%s is a binary operator\n", yytext); }

"a"|"b"|"c"|"d" { operands_count++; printf("%s is an operand\n", yytext); }

[ \t\n]+  /* Ignore whitespace. */

. { printf("Unrecognized character: %s\n", yytext); } /* Catch-all rule */

%%

int yywrap(void) { return 1; }

int main(void) {
    printf("Enter the arithmetic expression: ");
    yylex();
   
    if(valid && depth == 0 && operands_count - operators_count == 1) {
        printf("\nInvalid Expression\n");
    } 
    else {
        printf("\nValid Expression\n");
    }

    return 0;
}
