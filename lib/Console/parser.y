%{
#include <iostream>
%}

%token IDENTIFIER
%token INTEGER

%%
command : IDENTIFIER INTEGER { std::cout << "Command: " << $1 << ", Value: " << $2 << std::endl; }
        | IDENTIFIER { std::cout << "Command: " << $1 << std::endl; }
        ;
%%

int main() {
    yyparse();
    return 0;
}
