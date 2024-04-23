#include <iostream>
#include <cstdio>
#include "blif.tab.h"

extern FILE* yyin;
extern int yyparse();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file.blif>" << std::endl;
        return 1;
    }

    // Open the input BLIF file
    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        std::cerr << "Error: Failed to open input file " << argv[1] << std::endl;
        return 1;
    }

    // Set the input file for the lexer
    yyin = inputFile;

    // Parse the BLIF file
    yyparse();

    // Close the input file
    fclose(inputFile);

    return 0;
}

