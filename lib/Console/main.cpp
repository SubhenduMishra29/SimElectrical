#include <iostream>
#include <cstdlib> // For exit function
extern "C" {
    int yyparse();
}

int main() {
    std::cout << "Welcome to the custom console!" << std::endl;
    std::cout << "Enter commands or type 'exit' to quit:" << std::endl;
    yyparse();
    return 0;
}

