#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

int n; // Number of productions
char productions[MAX][MAX], follow[MAX][MAX];
char first[MAX][MAX], nullable[MAX];

void findFirst(char symbol, char result[]) {
    int i, j, k;
    char temp[MAX];

    if (!isupper(symbol)) {
        strncat(result, &symbol, 1);
        return;
    }

    for (i = 0; i < n; i++) {
        if (productions[i][0] == symbol) {
            if (productions[i][2] == '#') {
                strncat(result, "#", 1);
            } else {
                for (j = 2; j < strlen(productions[i]); j++) {
                    findFirst(productions[i][j], temp);
                    strncat(result, temp, strlen(temp));
                    if (strchr(nullable, productions[i][j]) == NULL) break;
                }
            }
        }
    }
}

void findFollow(char symbol) {
    int i, j, k;
    char temp[MAX];

    if (symbol == productions[0][0]) strncat(follow[0], "$", 1);

    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(productions[i]); j++) {
            if (productions[i][j] == symbol) {
                if (productions[i][j + 1] != '\0') {
                    findFirst(productions[i][j + 1], temp);
                    for (k = 0; temp[k] != '\0'; k++) {
                        if (temp[k] != '#') {
                            strncat(follow[symbol - 'A'], &temp[k], 1);
                        } else {
                            findFollow(productions[i][0]);
                            strncat(follow[symbol - 'A'], follow[productions[i][0] - 'A'], strlen(follow[productions[i][0] - 'A']));
                        }
                    }
                } else {
                    findFollow(productions[i][0]);
                    strncat(follow[symbol - 'A'], follow[productions[i][0] - 'A'], strlen(follow[productions[i][0] - 'A']));
                }
            }
        }
    }
}

void computeFollow() {
    int i;
    for (i = 0; i < n; i++) {
        findFollow(productions[i][0]);
    }
}

int main() {
    int i;
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions (E.g., E->T|T->F):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    memset(follow, 0, sizeof(follow));

    computeFollow();

    printf("FOLLOW sets:\n");
    for (i = 0; i < n; i++) {
        printf("FOLLOW(%c) = { %s }\n", productions[i][0], follow[productions[i][0] - 'A']);
    }
    return 0;
}