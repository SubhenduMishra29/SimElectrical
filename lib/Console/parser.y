%{
#include <iostream>
#include <cstdlib> // For exit function
%}

%token EXIT AND OR NOT IDENTIFIER CONSTANT

%%

statements : /* empty */ | statements statement ;

statement : EXIT { std::cout << "Exiting console..." << std::endl; exit(EXIT_SUCCESS); }
          | operation
          ;

operation : AND { std::cout << "Operation: AND" << std::endl; }
          | OR  { std::cout << "Operation: OR" << std::endl; }
          | NOT { std::cout << "Operation: NOT" << std::endl; }
          ;

%%

int main() {
    yyparse();
    return 0;
}


