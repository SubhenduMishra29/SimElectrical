%{
#include <iostream>
%}

%token NEWLINE MODEL INPUTS OUTPUTS NAMES END IDENTIFIER DIGIT

%%

blif_file : module_declaration_list { std::cout << "BLIF file parsed successfully!" << std::endl; }

module_declaration_list : /* empty */
                         | module_declaration_list module_declaration

module_declaration : MODEL IDENTIFIER
                    | INPUTS identifier_list
                    | OUTPUTS identifier_list
                    | NAMES identifier_list truth_table
                    | END

identifier_list : /* empty */
                 | identifier_list IDENTIFIER

truth_table : identifier_list DIGIT { std::cout << "Truth table: " << $1 << " -> " << $2 << std::endl; }

%%

int main() {
    yyparse();
    return 0;
}
