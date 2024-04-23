%{
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
unordered_set<string> inputSignals;
unordered_set<string> outputSignals;
unordered_set<string> clockSignals;
string currentModelName;

void addInput(const string& input) {
    inputSignals.insert(input);
}

void addOutput(const string& output) {
    outputSignals.insert(output);
}

void addClock(const string& clock) {
    clockSignals.insert(clock);
}

void printModelDeclaration() {
    cout << "Model Name: " << currentModelName << endl;
    cout << "Inputs: ";
    for (const string& input : inputSignals) {
        cout << input << " ";
    }
    cout << endl;
    cout << "Outputs: ";
    for (const string& output : outputSignals) {
        cout << output << " ";
    }
    cout << endl;
    cout << "Clocks: ";
    for (const string& clock : clockSignals) {
        cout << clock << " ";
    }
    cout << endl;
}

%}

%union {
    string str;
}

%token MODEL INPUTS OUTPUTS CLOCK END IDENTIFIER NEWLINE

%%

blif_file : model_declaration_list { cout << "BLIF file parsed successfully!" << endl; }

model_declaration_list : /* empty */
                        | model_declaration_list model_declaration

model_declaration : MODEL IDENTIFIER model_body END { printModelDeclaration(); }

model_body : input_list output_list clock_list command_list

input_list : /* empty */
           | input_list INPUTS identifier_list NEWLINE { for (const string& input : $3) addInput(input); }

output_list : /* empty */
            | output_list OUTPUTS identifier_list NEWLINE { for (const string& output : $3) addOutput(output); }

clock_list : /* empty */
           | clock_list CLOCK identifier_list NEWLINE { for (const string& clock : $3) addClock(clock); }

command_list : /* empty */
             | command_list command NEWLINE

identifier_list : /* empty */
                 | identifier_list IDENTIFIER { $$ = $1; }
                 | IDENTIFIER { $$ = { $1 }; }

command : IDENTIFIER { cout << "Command: " << $1 << endl; }

%%

int main() {
    yyparse();
    return 0;
}
