%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE *yyin;

void yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

%}

%union {
    double num;
    char *str;
}

%token <num> NUMBER
%token <str> NAME
%token EXIT NEWLINE MODEL INPUTS OUTPUTS LATCH START_KISS I O P S R END_KISS LATCH_ORDER CODE NAMES END

%%

blif_file: model_declaration END
          ;

model_declaration: optional_model inputs_declaration outputs_declaration latch_declaration start_kiss_declaration fsm_declaration latch_order_declaration code_declaration names_declaration END_KISS
                 ;

optional_model: /* empty */
              | MODEL NAME
              ;

inputs_declaration: /* empty */
                   | INPUTS input_list
                   ;

outputs_declaration: /* empty */
                    | OUTPUTS output_list
                    ;

latch_declaration: /* empty */
                  | LATCH latch_list
                  ;

start_kiss_declaration: /* empty */
                       | START_KISS I NUMBER O NUMBER P NUMBER S NUMBER R NAME NUMBER
                       ;

fsm_declaration: /* empty */
                 | fsm
                 ;

latch_order_declaration: /* empty */
                         | LATCH_ORDER latch_list
                         ;

code_declaration: /* empty */
                  | CODE code_list
                  ;

names_declaration: /* empty */
                   | NAMES names_list
                   ;

fsm: fsm_line fsm_lines
   ;

fsm_lines: /* empty */
         | fsm_line fsm_lines
         ;

fsm_line: NAME NAME NAME NAME
        ;

input_list: NAME
          | input_list NAME
          ;

output_list: NAME
           | output_list NAME
           ;

latch_list: /* empty */
          | LATCH NAME NAME NUMBER
          | latch_list LATCH NAME NAME NUMBER
          ;

code_list: /* empty */
         | CODE NAME NUMBER
         | code_list CODE NAME NUMBER
         ;

names_list: /* empty */
          | NAMES NAME NUMBER
          | names_list NAMES NAME NUMBER
          ;

%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    yyin = input_file;
    yyparse();
    fclose(input_file);

    return 0;
}
