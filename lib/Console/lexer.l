%{
#include "parser.tab.h"
%}

%%

[ \t\n]         /* ignore whitespace */
"exit"          { return EXIT; }
[a-zA-Z]+       { yylval.str = strdup(yytext); return IDENTIFIER; }
[0-9]+          { yylval.num = atoi(yytext); return INTEGER; }
.               { return yytext[0]; } /* return any other character as is */

%%
