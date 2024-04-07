#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10

int count, n = 0;
char production[MAX_PRODUCTIONS][MAX_SYMBOLS];
char first[MAX_PRODUCTIONS][MAX_SYMBOLS];
char f[MAX_SYMBOLS];
int k;

void findfirst(char c, int q1, int q2);

int main(int argc, char **argv) {
    printf("How many productions? : ");
    scanf("%d", &count);
    printf("\nEnter %d productions in form A=B where A and B are grammar symbols:\n\n", count);
    for (int i = 0; i < count; i++) {
        scanf("%s", production[i]);
    }

    // Compute first set for each non-terminal symbol
    for (int i = 0; i < count; i++) {
        findfirst(production[i][0], i, 2);
        printf("First(%c) = { ", production[i][0]);
        for (int j = 0; j < n; j++) {
            printf("%c, ", first[i][j]);
        }
        printf("}\n");
        n = 0; // Reset n for the next iteration
    }

    return 0;
}

void findfirst(char c, int q1, int q2) {
    int j;
    if (!(isupper(c))) {
        first[q1][n++] = c;
    } else {
        for (j = 0; j < count; j++) {
            if (production[j][0] == c) {
                if (production[j][2] == '#') {
                    if (production[q1][q2] == '\0') {
                        first[q1][n++] = '#';
                    } else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) {
                        findfirst(production[q1][q2], q1, (q2 + 1));
                    } else {
                        first[q1][n++] = '#';
                    }
                } else if (!isupper(production[j][2])) {
                    first[q1][n++] = production[j][2];
                } else {
                    findfirst(production[j][2], j, 3);
                }
            }
        }
    }
}
