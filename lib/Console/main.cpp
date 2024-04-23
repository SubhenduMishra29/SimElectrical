#include <iostream>
#include "blif_parser.tab.h"

extern FILE* yyin;
extern int yyparse();

int main() {
    yyin = fopen("input.blif", "r");
    if (!yyin) {
        std::cerr << "Error: Failed to open input file." << std::endl;
        return 1;
    }

    yyparse();

    fclose(yyin);

    return 0;
}

