#include <stdio.h>
#include <ctype.h>

char* input;
int current = 0;

void match(char expected) {
    if (input[current] == expected) {
        current++;
    } else {
        printf("Error: Expected %c, found %c\n", expected, input[current]);
        exit(1);
    }
}

void F() {
    if (input[current] == '(') {
        match('(');
        E();
        match(')');
    } else if (isalpha(input[current])) {
        current++; // Assuming identifier
    } else {
        printf("Error: Unexpected symbol %c\n", input[current]);
        exit(1);
    }
}

void T() {
    F();
    while (input[current] == '+') { // We simplify by assuming all ops are '+'
        match('+');
        F();
    }
}

void E() {
    T();
}

int main() {
    input = "x+(y+z)+(p+z)+u";
    E();
    if (input[current] == '\0') { // End of input
        printf("Parsing succeeded\n");
    } else {
        printf("Parsing failed\n");
    }
    return 0;
}
