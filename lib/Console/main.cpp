#include <iostream>
#include <cstdio>

extern "C" {
    int yyparse();
    FILE* yyin;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

    int result = yyparse();
    fclose(yyin);

    if (result == 0) {
        std::cout << "Parsing successful!" << std::endl;
    } else {
        std::cerr << "Parsing failed!" << std::endl;
    }

    return result;
}
