%{
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void yyerror(const char* s);
extern int yylex();
extern FILE* yyin;

// Define structures to store FSM description and clock constraints
struct FSMDescription {
    int numInputs;
    int numOutputs;
    vector<vector<string>> transitions;
};

struct ClockConstraint {
    double cycleTime;
    vector<pair<double, vector<string>>> events;
};

// Global variables to store FSM description and clock constraints
FSMDescription fsmDescription;
ClockConstraint clockConstraint;

// Function to print FSM description
void printFSMDescription() {
    cout << "FSM Description:\n";
    cout << "Number of Inputs: " << fsmDescription.numInputs << endl;
    cout << "Number of Outputs: " << fsmDescription.numOutputs << endl;
    cout << "Transitions:\n";
    for (const auto& transition : fsmDescription.transitions) {
        for (const auto& elem : transition) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to print clock constraints
void printClockConstraint() {
    cout << "Clock Constraint:\n";
    cout << "Cycle Time: " << clockConstraint.cycleTime << endl;
    cout << "Events:\n";
    for (const auto& event : clockConstraint.events) {
        cout << "Event Percent: " << event.first << endl;
        cout << "Clocks:";
        for (const auto& clock : event.second) {
            cout << " " << clock;
        }
        cout << endl;
    }
    cout << endl;
}
%}

%token MODEL START_KISS END_KISS INPUTS OUTPUTS CLOCK END NAMES EXDC LATCH LIBGATE MLATCH SUBCKT SEARCH IDENTIFIER '=' NEWLINE
%token <str> STR_LITERAL
%token <num> NUM_LITERAL

%%

program: model_desc fsm_desc clock_desc
       ;

model_desc: MODEL STR_LITERAL inputs outputs latches gates
          | MODEL STR_LITERAL inputs outputs latches gates fsm_desc
          | MODEL STR_LITERAL inputs outputs latches gates clock_desc
          | MODEL STR_LITERAL inputs outputs latches gates fsm_desc clock_desc
          ;

inputs: INPUTS id_list NEWLINE
      ;

outputs: OUTPUTS id_list NEWLINE
       ;

id_list: IDENTIFIER
       | IDENTIFIER id_list
       ;

latches: /* empty */
       | latches latched
       ;

latched: LATCH IDENTIFIER IDENTIFIER ['=' IDENTIFIER] ['[' IDENTIFIER ']'] ['[' IDENTIFIER ']'] NEWLINE
        ;

gates: /* empty */
     | gates gate
     ;

gate: LIBGATE IDENTIFIER formal_actual_list NEWLINE
    | MLATCH IDENTIFIER formal_actual_list IDENTIFIER ['=' IDENTIFIER] NEWLINE
    ;

formal_actual_list: /* empty */
                  | formal_actual_list IDENTIFIER '=' IDENTIFIER
                  ;

fsm_desc: START_KISS '.i' NUM_LITERAL '.o' NUM_LITERAL fsm_desc_body END_KISS
        {
            fsmDescription.numInputs = $3;
            fsmDescription.numOutputs = $5;
        }
        ;

fsm_desc_body: /* empty */
             | fsm_desc_body fsm_desc_line
             ;

fsm_desc_line: NUM_LITERAL IDENTIFIER IDENTIFIER IDENTIFIER NEWLINE
             {
                 fsmDescription.transitions.push_back({to_string($1), $2, $3, $4});
             }
             ;

clock_desc: /* empty */
          | '.cycle' NUM_LITERAL NEWLINE
            {
                clockConstraint.cycleTime = $2;
            }
          | clock_desc clock_event
          ;

clock_event: '.clock_event' NUM_LITERAL event_list NEWLINE
            {
                clockConstraint.events.push_back({$2, $3});
            }
           ;

event_list: IDENTIFIER
          | IDENTIFIER event_list
          ;

%%

void yyerror(const char* s) {
    cerr << "Parser Error: " << s << " at line " << yylineno << endl;
}

int main() {
    yyin = fopen("input.blif", "r");
    if (!yyin) {
        cerr << "Error: Failed to open input file." << endl;
        return 1;
    }

    yyparse();

    fclose(yyin);

    // Print FSM description and clock constraints
    printFSMDescription();
    printClockConstraint();

    return 0;
}
