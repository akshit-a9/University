%{
    #include<stdio.h>
%}

%%
if |
else |
printf {printf("%s is a keyword ",yytext);}
[0-9]+ {printf("%s is a number ",yytext);}
[a-zA-Z!]+ {printf("%s is a word ",yytext);}
[(]+ {printf("%s is a paranthesis ",yytext);}
[)]+ {printf("%s is a paranthesis ",yytext);}
["]+ {printf("%s is a qoute ",yytext);}
[++] {printf("%s is a incremental ",yytext);}
"+" {printf("%s is a addition ", yytext);}

[=] {printf("%s is a equal to operator",yytext);}
.|\n {ECHO;}
%%

int main() {
   
    yylex();
}

int yywrap(){
    return 1;
}
