#include <iostream>
extern "C" {
    int yyparse();
}

int main() {
    std::cout << "Welcome to the custom console!" << std::endl;
    std::cout << "Enter commands:" << std::endl;
    yyparse();
    return 0;
}
