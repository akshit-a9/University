#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <map>

using namespace std;


enum TokenType {
    SWITCH, CASE, DEFAULT, BREAK, IDENTIFIER, STRING_LITERAL, LBRACE, RBRACE, LPAREN, RPAREN, COLON, SEMICOLON, END
};

struct Token {
    TokenType type;
    string value;
    int line;
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
        } else if (code.substr(i, 5) == "break") {
            tokens.push_back({BREAK, "break", line});
            i += 5;
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
        } else if (isalnum(code[i]) || code[i] == '_') {
            size_t start = i;
            while (i < code.size() && (isalnum(code[i]) || code[i] == '_')) {
                i++;
            }
            tokens.push_back({IDENTIFIER, code.substr(start, i - start), line});
        } else if (code[i] == '"') {
            size_t start = i;
            i++;
            while (i < code.size() && code[i] != '"') {
                i++;
            }
            i++;
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

map<int, map<TokenType, string>> ACTION = {
    {0, {{SWITCH, "s2"}, {BREAK, "s11"}, {CASE, "s7"}, {DEFAULT, "s7"}, {RBRACE, "s13"}}},
    {1, {{END, "accept"}}},
    {2, {{LPAREN, "s3"}}},
    {3, {{IDENTIFIER, "s4"}}},
    {4, {{RPAREN, "s5"}}},
    {5, {{LBRACE, "s6"}}},
    {6, {{CASE, "s7"}, {DEFAULT, "s10"}, {RBRACE, "s13"}}},
    {7, {{IDENTIFIER, "s8"}, {COLON, "s12"}, {END, "accept"}}},
    {8, {{COLON, "s9"}}},
    {9, {{IDENTIFIER, "s14"}, {STRING_LITERAL, "s15"}, {BREAK, "s11"}, {CASE, "r3"}, {DEFAULT, "r3"}, {RBRACE, "r3"}}},
    {10, {{COLON, "s12"}}},
    {11, {{SEMICOLON, "s16"}}},
    {12, {{IDENTIFIER, "s14"}, {STRING_LITERAL, "s15"}, {BREAK, "s11"}, {CASE, "r4"}, {RBRACE, "r4"}}},
    {13, {{END, "r2"}}},
    {14, {{SEMICOLON, "s17"}, {STRING_LITERAL, "s15"}}},
    {15, {{SEMICOLON, "s17"}}},
    {16, {{CASE, "r7"}, {DEFAULT, "r7"}, {RBRACE, "s7"}}},
    {17, {{IDENTIFIER, "r8"}, {STRING_LITERAL, "r8"}, {BREAK, "r8"}, {CASE, "r8"}, {DEFAULT, "r8"}, {RBRACE, "r8"}}}
};

map<int, map<string, int>> GOTO = {
    {0, {{"S", 1}, {"switch_block", 2}}},
    {6, {{"case_blocks", 9}, {"case_block", 7}}},
    {9, {{"case_blocks", 6}, {"case_block", 7}}},
    {12, {{"default_block", 13}}},
    {13, {{"statements", 6}, {"statement", 9}}},
    {9, {{"statement", 14}}},
    {12, {{"statement", 14}}},
    {14, {{"statement", 9}}}
};

struct Production {
    string lhs;
    int rhs_size;
};

vector<Production> productions = {
    {"S'", 1}, {"S", 1}, {"switch_block", 5}, {"case_block", 3}, {"default_block", 2},
    {"statements", 1}, {"statements", 2}, {"statement", 2}, {"statement", 3}
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
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Unable to open file input.txt" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string code = buffer.str();
    inputFile.close();

    vector<Token> tokens = lexer(code);
    cout << "Tokens:" << endl;
    for (const auto &token : tokens) {
        cout << "Type: " << token.type << ", Value: " << token.value << ", Line: " << token.line << endl;
    }
    parse(tokens);
    return 0;
}
