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

void printExternalDon'tCares(const string& outputSignal, const vector<string>& inputSignals, const vector<string>& cover) {
    cout << "External Don't Cares Declaration:" << endl;
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

void printLatch(const string& inputSignal, const string& outputSignal, const string& type, const string& control, const string& initVal) {
    cout << "Latch Declaration:" << endl;
    cout << "Input Signal: " << inputSignal << endl;
    cout << "Output Signal: " << outputSignal << endl;
    cout << "Type: " << type << endl;
    cout << "Control: " << control << endl;
    cout << "Init Val: " << initVal << endl;
}

void printLibraryGate(const string& name, const vector<string>& formalActualList, const string& control, const string& initVal) {
    cout << "Library Gate Declaration:" << endl;
    cout << "Name: " << name << endl;
    cout << "Formal Actual List: ";
    for (const string& mapping : formalActualList) {
        cout << mapping << " ";
    }
    cout << endl;
    cout << "Control: " << control << endl;
    cout << "Init Val: " << initVal << endl;
}

void printModelReference(const string& modelName, const vector<string>& formalActualList) {
    cout << "Model Reference:" << endl;
    cout << "Model Name: " << modelName << endl;
    cout << "Formal Actual List: ";
    for (const string& mapping : formalActualList) {
        cout << mapping << " ";
    }
    cout << endl;
}

void printSubfileReference(const string& fileName) {
    cout << "Subfile Reference:" << endl;
    cout << "File Name: " << fileName << endl;
}

%}

%union {
    string str;
    vector<string> str_vector;
}

%token MODEL INPUTS OUTPUTS CLOCK END IDENTIFIER NEWLINE
%token NAMES EXDC LATCH LIBGATE MLATCH SUBCKT SEARCH

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
        | EXDC NAMES IDENTIFIER identifier_list cover { printExternalDon'tCares($3, $4, $5); }
        | LATCH IDENTIFIER IDENTIFIER IDENTIFIER IDENTIFIER { printLatch($3, $4, $5, $6, $7); }
        | LIBGATE IDENTIFIER formal_actual_list IDENTIFIER IDENTIFIER { printLibraryGate($2, $3, $4, $5); }
        | MLATCH IDENTIFIER formal_actual_list IDENTIFIER IDENTIFIER { printLibraryGate($2, $3, $4, $5); }
        | SUBCKT IDENTIFIER formal_actual_list { printModelReference($2, $3); }
        | SEARCH IDENTIFIER { printSubfileReference($2); }

cover : /* empty */
      | cover IDENTIFIER { $$ = { $1 }; }

formal_actual_list : /* empty */
                    | formal_actual_list IDENTIFIER '=' IDENTIFIER { $$ = { $1, $3 }; }

%%

int main() {
    yyparse();
    return 0;
}
