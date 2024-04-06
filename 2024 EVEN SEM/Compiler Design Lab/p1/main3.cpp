#include <iostream>
#include <cctype>

using namespace std;

// Token types
enum TokenType {
    TOK_EOF,
    TOK_ID,
    TOK_PLUS,
    TOK_MULTIPLY,
    TOK_DIVIDE
};

// Token structure
struct Token {
    TokenType type;
    char value; // for ID token
};

// Simple lexer to tokenize input expression
class Lexer {
public:
    Lexer(const string& input) : input(input), position(0) {}

    Token getNextToken() {
        while (position < input.size()) {
            char currentChar = input[position];

            if (isspace(currentChar)) {
                // Skip whitespace
                position++;
                continue;
            }

            if (isalpha(currentChar)) {
                // ID token
                return Token{ TOK_ID, currentChar };
            }

            if (currentChar == '+') {
                // Plus token
                position++;
                return Token{ TOK_PLUS, '+' };
            }

            if (currentChar == '*') {
                // Multiply token
                position++;
                return Token{ TOK_MULTIPLY, '*' };
            }

            if (currentChar == '/') {
                // Divide token
                position++;
                return Token{ TOK_DIVIDE, '/' };
            }

            // Unexpected character
            cerr << "Unexpected character: " << currentChar << endl;
            exit(1);
        }

        // End of input
        return Token{ TOK_EOF, '\0' };
    }

private:
    const string& input;
    size_t position;
};

// Recursive descent parser
class Parser {
public:
    Parser(Lexer& lexer) : lexer(lexer) {}

    void parse() {
        // Prime the parser
        currentToken = lexer.getNextToken();
        expr();
    }

private:
    void expr() {
        // Production: E -> term E'
        term();
        exprTail();
    }

    void exprTail() {
        // Production: E' -> + term E' | ε
        if (currentToken.type == TOK_PLUS) {
            match(TOK_PLUS);
            term();
            exprTail();
        }
    }

    void term() {
        // Production: term -> T T'
        factor();
        termTail();
    }

    void termTail() {
        // Production: T' -> * F T' | / F T' | ε
        if (currentToken.type == TOK_MULTIPLY) {
            match(TOK_MULTIPLY);
            factor();
            termTail();
        } else if (currentToken.type == TOK_DIVIDE) {
            match(TOK_DIVIDE);
            factor();
            termTail();
        }
    }

    void factor() {
        // Production: F -> id
        if (currentToken.type == TOK_ID) {
            match(TOK_ID);
        } else {
            cerr << "Syntax error: Expected ID" << endl;
            exit(1);
        }
    }

    void match(TokenType expectedToken) {
        if (currentToken.type == expectedToken) {
            currentToken = lexer.getNextToken();
        } else {
            cerr << "Syntax error: Unexpected token" << endl;
            exit(1);
        }
    }

private:
    Lexer& lexer;
    Token currentToken;
};

int main() {
    string input = "x+(y*z)+(p*q)+u";
    Lexer lexer(input);
    Parser parser(lexer);
    parser.parse();
    cout << "Parsing successful!" << endl;
    return 0;
}