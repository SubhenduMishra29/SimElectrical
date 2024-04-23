%{
#include "blif.tab.h"
%}

%%

\.area             { return AREA; }
\.delay            { return DELAY; }
\.wire_load_slope { return WIRE_LOAD_SLOPE; }
\.wire             { return WIRE; }
\.input_arrival    { return INPUT_ARRIVAL; }
\.default_input_arrival { return DEFAULT_INPUT_ARRIVAL; }
\.output_required  { return OUTPUT_REQUIRED; }
\.default_output_required { return DEFAULT_OUTPUT_REQUIRED; }
\.input_drive      { return INPUT_DRIVE; }
\.default_input_drive { return DEFAULT_INPUT_DRIVE; }
\.max_input_load   { return MAX_INPUT_LOAD; }
\.default_max_input_load { return DEFAULT_MAX_INPUT_LOAD; }
\.output_load      { return OUTPUT_LOAD; }
\.default_output_load { return DEFAULT_OUTPUT_LOAD; }
[0-9]+(\.[0-9]+)?  { yylval.num = atof(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return NAME; }
[ \t\n]            ;  // Ignore whitespace and newline characters
.                  ;  // Ignore any other character

%%

int yywrap() {
    return 1;
}
