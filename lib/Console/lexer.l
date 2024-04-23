%{
#include "parser.tab.h"
%}

%%

[ \t\n]         /* ignore whitespace */
"exit"          { return EXIT; }
"and"           { return AND; }
"or"            { return OR; }
"not"           { return NOT; }
[a-zA-Z]+       { yylval.str = strdup(yytext); return IDENTIFIER; }
[01]            { yylval.num = atoi(yytext); return CONSTANT; }
.               { return yytext[0]; } /* return any other character as is */

%%
