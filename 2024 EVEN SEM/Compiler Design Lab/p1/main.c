#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* input;
int i = 0;

void E();
void Edash();
void T();
void Tdash();
void F();

void E() {
    T();
    Edash();
}

void Edash() {
    if (input[i] == '+') {
        i++;
        T();
        Edash();
    }
}

void T() {
    F();
    Tdash();
}

void Tdash() {
    if (input[i] == '+') {
        i++;
        F();
        Tdash();
    }
}

void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            printf("Error: Missing closing parenthesis\n");
            exit(1);
        }
    } else if (isalpha(input[i])) {
        i++;
    } else {
        printf("Error: Unexpected symbol %c\n", input[i]);
        exit(1);
    }
}

int main() {
    input = "x+(y+z)+(p+z)+u$";
    E();
    if (input[i] == '$') {
        printf("Parsing succeeded\n");
    } else {
        printf("Parsing failed\n");
    }
    return 0;
}
