%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE* yyin;
extern char* yytext;
extern int yylval;

void yyerror(const char* s);

%}

%token AREA DELAY WIRE_LOAD_SLOPE WIRE INPUT_ARRIVAL DEFAULT_INPUT_ARRIVAL OUTPUT_REQUIRED DEFAULT_OUTPUT_REQUIRED
%token INPUT_DRIVE DEFAULT_INPUT_DRIVE MAX_INPUT_LOAD DEFAULT_MAX_INPUT_LOAD OUTPUT_LOAD DEFAULT_OUTPUT_LOAD
%token NUMBER NAME

%%

input: 
    | input delay_constraint
    | input wire_constraint
    | input input_arrival_constraint
    | input output_required_constraint
    | input input_drive_constraint
    | input max_input_load_constraint
    | input output_load_constraint
    ;

delay_constraint: DELAY NAME NAME NUMBER NUMBER NUMBER NUMBER NUMBER { /* action */ }
    ;

wire_constraint: WIRE_LOAD_SLOPE NUMBER { /* action */ }
    | WIRE NUMBER { /* action */ }
    ;

input_arrival_constraint: INPUT_ARRIVAL NAME NUMBER NUMBER { /* action */ }
    | DEFAULT_INPUT_ARRIVAL NUMBER NUMBER { /* action */ }
    ;

output_required_constraint: OUTPUT_REQUIRED NAME NUMBER NUMBER { /* action */ }
    | DEFAULT_OUTPUT_REQUIRED NUMBER NUMBER { /* action */ }
    ;

input_drive_constraint: INPUT_DRIVE NAME NUMBER NUMBER { /* action */ }
    | DEFAULT_INPUT_DRIVE NUMBER NUMBER { /* action */ }
    ;

max_input_load_constraint: MAX_INPUT_LOAD NUMBER { /* action */ }
    | DEFAULT_MAX_INPUT_LOAD NUMBER { /* action */ }
    ;

output_load_constraint: OUTPUT_LOAD NAME NUMBER { /* action */ }
    | DEFAULT_OUTPUT_LOAD NUMBER { /* action */ }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Parser error: %s\n", s);
}

int main(int argc, char* argv[]) {
    yyin = fopen(argv[1], "r");
    yyparse();
    fclose(yyin);
    return 0;
}
