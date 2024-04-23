%{
#include "blif_parser.tab.h"
#include <iostream>
#include <vector>
using namespace std;
extern int yylineno;
extern char* yytext;
%}

%option noyywrap

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
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
\.                      { return yytext[0]; }
.                       { cerr << "Lexer Error: Unrecognized token at line " << yylineno << endl; }

%%

int yywrap() {
    return 1;
}

