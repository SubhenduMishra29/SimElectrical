%{
#include <iostream>
#include <vector>
using namespace std;
string currentOutputSignal;

void printLogicGateDeclaration(const string& outputSignal, const vector<string>& inputSignals, const vector<string>& cover) {
    cout << "Logic Gate Declaration:" << endl;
    cout << "Output Signal: " << outputSignal << endl;
    cout << "Input Signals: ";
    for (const string& input : inputSignals) {
        cout << input << " ";
    }
    cout << endl;
    cout << "Single Output Cover:" << endl;
    for (const string& row : cover) {
        cout << row << endl;
    }
}

%}

%union {
    string str;
    vector<string> str_vector;
}

%token MODEL INPUTS OUTPUTS CLOCK END IDENTIFIER NEWLINE
%token NAMES

%%

blif_file : model_declaration_list { cout << "BLIF file parsed successfully!" << endl; }

model_declaration_list : /* empty */
                        | model_declaration_list model_declaration

model_declaration : MODEL IDENTIFIER model_body END

model_body : input_list output_list clock_list command_list

input_list : /* empty */
           | input_list INPUTS identifier_list NEWLINE

output_list : /* empty */
            | output_list OUTPUTS identifier_list NEWLINE

clock_list : /* empty */
           | clock_list CLOCK identifier_list NEWLINE

command_list : /* empty */
             | command_list command NEWLINE

identifier_list : /* empty */
                 | identifier_list IDENTIFIER
                 | IDENTIFIER { $$ = { $1 }; }

command : NAMES IDENTIFIER identifier_list cover { printLogicGateDeclaration(currentOutputSignal, $3, $4); }

cover : /* empty */
      | cover IDENTIFIER { $$ = { $1 }; }

%%

int main() {
    yyparse();
    return 0;
}
