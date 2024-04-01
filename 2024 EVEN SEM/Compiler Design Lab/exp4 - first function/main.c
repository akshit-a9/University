#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_PRODUCTIONS 10
#define NUM_OF_NONTERMINALS 10
#define MAX_PRODUCTION_LENGTH 10
#define NUM_OF_TERMINALS 10

typedef struct {
    char nonterminal;
    char production[MAX_PRODUCTION_LENGTH];
} Production;

typedef struct {
    char symbol;
    char firstSet[NUM_OF_TERMINALS];
} FirstSet;

// Function prototypes
int isNonterminal(char symbol);
void computeFirstSets(FirstSet firstSets[], Production productions[], int numOfProductions);

int main() {
    Production productions[NUM_OF_PRODUCTIONS]; // You should fill this with your grammar productions
    FirstSet firstSets[NUM_OF_NONTERMINALS]; // This will store the FIRST sets for nonterminals

    int numOfProductions = 0; // Set this to the actual number of productions you have

    // Initialize productions and number of productions...
    
    computeFirstSets(firstSets, productions, numOfProductions);

    // Display the FIRST sets...
    for (int i = 0; i < NUM_OF_NONTERMINALS; i++) {
        if (firstSets[i].symbol != '\0') {
            printf("FIRST(%c) = { ", firstSets[i].symbol);
            for (int j = 0; firstSets[i].firstSet[j] != '\0'; j++) {
                printf("%c ", firstSets[i].firstSet[j]);
            }
            printf("}\n");
        }
    }

    return 0;
}

int isNonterminal(char symbol) {
    // Logic to check if the symbol is a nonterminal
    // Usually nonterminals are uppercase letters
    return symbol >= 'A' && symbol <= 'Z';
}

void addToFirstSet(char firstSet[], char symbolToAdd) {
    if (strchr(firstSet, symbolToAdd) == NULL) {
        int len = strlen(firstSet);
        firstSet[len] = symbolToAdd;
        firstSet[len + 1] = '\0';
    }
}

void computeFirstSets(FirstSet firstSets[], Production productions[], int numOfProductions) {
    int changes;
    do {
        changes = 0;
        for (int i = 0; i < numOfProductions; i++) {
            char nonterminal = productions[i].nonterminal;
            char* production = productions[i].production;

            FirstSet* currentFirstSet = NULL;
            for (int j = 0; j < NUM_OF_NONTERMINALS; j++) {
                if (firstSets[j].symbol == nonterminal || firstSets[j].symbol == '\0') {
                    currentFirstSet = &firstSets[j];
                    if (firstSets[j].symbol == '\0') {
                        firstSets[j].symbol = nonterminal;
                        firstSets[j].firstSet[0] = '\0';
                    }
                    break;
                }
            }

            if (production[0] == 'e') { // epsilon
                if (strchr(currentFirstSet->firstSet, 'e') == NULL) {
                    addToFirstSet(currentFirstSet->firstSet, 'e');
                    changes = 1;
                }
            } else {
                for (int j = 0; production[j] != '\0'; j++) {
                    if (!isNonterminal(production[j]) || production[j] == 'e') {
                        addToFirstSet(currentFirstSet->firstSet, production[j]);
                        break;
                    } else {
                        // Add FIRST(Yj) to FIRST(X)
                        for (int k = 0; k < NUM_OF_NONTERMINALS; k++) {
                            if (firstSets[k].symbol == production[j]) {
                                int len = strlen(firstSets[k].firstSet);
                                for (int l = 0; l < len; l++) {
                                    if (firstSets[k].firstSet[l] != 'e') {
                                        if (addToFirstSet(currentFirstSet->firstSet, firstSets[k].firstSet[l])) {
                                            changes = 1;
                                        }
                                    } else if (production[j + 1] == '\0') {
                                        if (addToFirstSet(currentFirstSet->firstSet, 'e')) {
                                            changes = 1;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    } while (changes);
}
