#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

enum TokenType {
    SWITCH, CASE, DEFAULT, IDENTIFIER, NUMBER, STRING_LITERAL, LBRACE, RBRACE, LPAREN, RPAREN, COLON, SEMICOLON, END
};


struct Token {
    TokenType type;
    string value;
    int line;
};


struct Production {
    string lhs;  
    int rhs_size; 
};

vector<Token> lexer(const string &code) {
    vector<Token> tokens;
    int line = 1;
    size_t i = 0;
    while (i < code.size()) {
        if (code.substr(i, 6) == "switch") {
            tokens.push_back({SWITCH, "switch", line});
            i += 6;
        } else if (code.substr(i, 4) == "case") {
            tokens.push_back({CASE, "case", line});
            i += 4;
        } else if (code.substr(i, 7) == "default") {
            tokens.push_back({DEFAULT, "default", line});
            i += 7;
        } else if (code[i] == '{') {
            tokens.push_back({LBRACE, "{", line});
            i++;
        } else if (code[i] == '}') {
            tokens.push_back({RBRACE, "}", line});
            i++;
        } else if (code[i] == '(') {
            tokens.push_back({LPAREN, "(", line});
            i++;
        } else if (code[i] == ')') {
            tokens.push_back({RPAREN, ")", line});
            i++;
        } else if (code[i] == ':') {
            tokens.push_back({COLON, ":", line});
            i++;
        } else if (code[i] == ';') {
            tokens.push_back({SEMICOLON, ";", line});
            i++;
        } else if (isdigit(code[i])) {
            size_t start = i;
            while (i < code.size() && isdigit(code[i])) i++;
            tokens.push_back({NUMBER, code.substr(start, i - start), line});
        } else if (isalpha(code[i])) {
            size_t start = i;
            while (i < code.size() && (isalnum(code[i]) || code[i] == '_')) i++;
            tokens.push_back({IDENTIFIER, code.substr(start, i - start), line});
        } else if (code[i] == '"') {
            size_t start = i++;
            while (i < code.size() && code[i] != '"') i++;
            i++;  // Skip closing quote
            tokens.push_back({STRING_LITERAL, code.substr(start, i - start), line});
        } else if (code[i] == '\n') {
            line++;
            i++;
        } else {
            i++;
        }
    }
    tokens.push_back({END, "$", line});
    return tokens;
}

vector<Production> productions = {
    {"switch_block", 3}, {"cases", 1}, {"cases", 2}, {"case_stat", 2},
    {"default_case", 2}, {"statement", 1}
};

map<int, map<TokenType, string>> ACTION = {
    {0, {{SWITCH, "s1"}}},
    {1, {{LBRACE, "s2"}}},
    {2, {{CASE, "s3"}, {DEFAULT, "s5"}, {RBRACE, "r2"}}},
    {3, {{NUMBER, "s4"}, {IDENTIFIER, "s4"}}},
    {4, {{COLON, "s6"}}},
    {5, {{COLON, "s7"}}},
    {6, {{IDENTIFIER, "s8"}, {RBRACE, "r4"}, {CASE, "r4"}, {DEFAULT, "r4"}}},
    {7, {{IDENTIFIER, "s8"}, {RBRACE, "r5"}}},
    {8, {{SEMICOLON, "s9"}}},
    {9, {{RBRACE, "r6"}, {CASE, "s3"}, {DEFAULT, "s5"}}}
};

map<int, map<string, int>> GOTO = {
    {0, {{"switch_block", 1}}},
    {2, {{"cases", 10}, {"case_stat", 3}, {"default_case", 5}}},
    {10, {{"more_cases", 2}}}
};

void parse(const vector<Token> &tokens) {
    stack<int> state_stack;
    stack<Token> symbol_stack;
    state_stack.push(0);
    int index = 0;

    while (index < tokens.size()) {
        int state = state_stack.top();
        Token token = tokens[index];
        TokenType token_type = token.type;
        string action = ACTION[state][token_type];

        cout << "State: " << state << ", Token: " << token.value << ", Action: " << action << endl; // Debugging output

        if (action[0] == 's') {
            int next_state = stoi(action.substr(1));
            state_stack.push(next_state);
            symbol_stack.push(token);
            index++;
        } else if (action[0] == 'r') {
            int production_index = stoi(action.substr(1));
            Production production = productions[production_index];

            for (int i = 0; i < production.rhs_size; ++i) {
                state_stack.pop();
                symbol_stack.pop();
            }

            Token non_terminal = {IDENTIFIER, production.lhs, token.line};
            symbol_stack.push(non_terminal);
            int next_state = GOTO[state_stack.top()][production.lhs];
            state_stack.push(next_state);
        } else if (action == "accept") {
            cout << "Parsing successful!" << endl;
            return;
        } else {
            cerr << "Syntax error at line " << token.line << "!" << endl;
            cerr << token.value << endl;
            return;
        }
    }
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file 'input.txt'" << endl;
        return -1;
    }

    string code((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    vector<Token> tokens = lexer(code);
    cout << "Tokens:" << endl;
    for (const auto &token : tokens) {
        cout << "Type: " << token.type << ", Value: " << token.value << ", Line: " << token.line << endl;
    }

    parse(tokens);
    return 0;
}
