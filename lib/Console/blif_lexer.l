%{
#include <iostream>
#include <string>
#include "blif.tab.h"
using namespace std;
extern int yylval;
extern FILE* yyin;
%}

%%

[ \t]+                  /* skip whitespace */
\n                      { return NEWLINE; }
\.model                 { return MODEL; }
\.inputs                { return INPUTS; }
\.outputs               { return OUTPUTS; }
\.clock                 { return CLOCK; }
\.end                   { return END; }
\.names                 { return NAMES; }
\.exdc                  { return EXDC; }
\.latch                 { return LATCH; }
\.gate                  { return LIBGATE; }
\.mlatch                { return MLATCH; }
\.subckt                { return SUBCKT; }
\.search                { return SEARCH; }
[0-9]+                  { yylval = atoi(yytext); return NUM_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval = strdup(yytext); return IDENTIFIER; }
\".*\"                  { yylval = strdup(yytext); return STR_LITERAL; }

%%

int yywrap() {
    return 1;
}
