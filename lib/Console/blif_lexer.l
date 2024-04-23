%{
#include "blif_parser.tab.h"
%}

%%

[\t ]+                  /* skip whitespace */
\n                      { return NEWLINE; }
\.model                 { return MODEL; }
\.inputs                { return INPUTS; }
\.outputs               { return OUTPUTS; }
\.names                 { return NAMES; }
\.end                   { return END; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
[01]                    { return DIGIT; }
.                       { return yytext[0]; } /* return any other character as is */

%%

