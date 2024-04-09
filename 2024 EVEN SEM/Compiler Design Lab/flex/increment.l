%{
    #include<stdio.h>
%}

%%
if |
else |
printf {printf("%s is a keyword \n",yytext);}
[0-9]+ {printf("%s is a number \n",yytext);}
[a-zA-Z!]+ {printf("%s is a word \n",yytext);}
[(]+ {printf("%s is a paranthesis \n",yytext);}
[)]+ {printf("%s is a paranthesis \n",yytext);}
["]+ {printf("%s is a qoute \n",yytext);}
[++]+ {printf("%s is a incremental \n",yytext);}
[+]= {printf("%s is a addition \n", yytext);}
[=] {printf("%s is a equal to operator \n",yytext);}
.|\n {ECHO;}
%%

int main() {
   
    yylex();
}

int yywrap(){
    return 1;
}
