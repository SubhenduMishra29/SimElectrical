%{
#include "blif.tab.h"
%}

%%

# Definitions for keywords
\.model                 { return MODEL; }
\.inputs                { return INPUTS; }
\.outputs               { return OUTPUTS; }
\.clock                 { return CLOCK; }
\.end                   { return END; }
\.names                 { return NAMES; }
\.gate                  { return GATE; }
\.exdc                  { return EXDC; }
\.latch                 { return LATCH; }
\.mlatch                { return MLATCH; }
\.subckt                { return SUBCKT; }
\.search                { return SEARCH; }
\.start_kiss            { return START_KISS; }
\.end_kiss              { return END_KISS; }
\.area                  { return AREA; }
\.delay                 { return DELAY; }
\.wire_load_slope       { return WIRE_LOAD_SLOPE; }
\.wire                  { return WIRE; }
\.input_arrival         { return INPUT_ARRIVAL; }
\.default_input_arrival { return DEFAULT_INPUT_ARRIVAL; }
\.output_required       { return OUTPUT_REQUIRED; }
\.default_output_required { return DEFAULT_OUTPUT_REQUIRED; }
\.input_drive           { return INPUT_DRIVE; }
\.default_input_drive   { return DEFAULT_INPUT_DRIVE; }
\.max_input_load        { return MAX_INPUT_LOAD; }
\.default_max_input_load { return DEFAULT_MAX_INPUT_LOAD; }
\.output_load           { return OUTPUT_LOAD; }
\.default_output_load  { return DEFAULT_OUTPUT_LOAD; }

# Definitions for other tokens
[\t ]+                  ;  // skip whitespace
\n                      { return NEWLINE; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return NAME; }
[0-9]+(\.[0-9]+)?      { yylval.num = atof(yytext); return NUMBER; }
\#.*                    ; // skip comments
.                       ; // catch-all for unrecognized characters

%%

int yywrap() {
    return 1;
}
