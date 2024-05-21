#include <iostream>
#include <stack>
#include <map>
#include <string>

using namespace std;

struct Action {
    char type; 
    int number; 
};

map<pair<int, char>, Action> parseTable;

void initializeParseTable() {
    
    parseTable[{0, 'a'}] = {'s', 5};
    parseTable[{0, 'b'}] = {'s', 6};
    parseTable[{0, 'c'}] = {'s', 7};
    parseTable[{0, 'd'}] = {'s', 8};
    parseTable[{0, 'e'}] = {'s', 9};

    parseTable[{0, 'F'}] = {'s', 1};
    parseTable[{0, 'T'}] = {'s', 2};
    parseTable[{0, 'E'}] = {'s', 3};

    parseTable[{1, '*'}] = {'s', 4};
    parseTable[{4, 'a'}] = {'s', 5};
    parseTable[{4, 'b'}] = {'s', 6};
    parseTable[{4, 'c'}] = {'s', 7};
    parseTable[{4, 'd'}] = {'s', 8};
    parseTable[{4, 'e'}] = {'s', 9};

    parseTable[{3, '$'}] = {'a', 0};
}

bool parseString(const string& input) {
    stack<int> stateStack;
    stateStack.push(0);  

    int i = 0;
    while (i < input.size()) {
        int currentState = stateStack.top();
        char currentSymbol = input[i];
        auto action = parseTable[{currentState, currentSymbol}];

        if (action.type == 's') { 
            stateStack.push(action.number);
            i++;
        } else if (action.type == 'r') { 
            stateStack.pop(); 
            char lhs = 'E';  
            currentState = stateStack.top();
            stateStack.push(parseTable[{currentState, lhs}].number);
        } else if (action.type == 'a') {
            cout << "The input string is accepted by the grammar." << endl;
            return true;
        } else {
            cout << "Error: Invalid string for the given grammar." << endl;
            return false;
        }
    }

    cout << "Error: Reached end of input without acceptance." << endl;
    return false;
}

int main() {
    initializeParseTable();
    string input = "a*b/c*d/e$"; 

    if (!parseString(input)) {
        cout << "The input string is rejected by the grammar." << endl;
    }

    return 0;
}
