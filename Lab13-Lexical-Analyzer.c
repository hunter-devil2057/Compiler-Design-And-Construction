#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_TOKEN_LENGTH 100
// List of valid operators
const char *operators[] = {"+", "-", "*", "/", "%", "++", "--", "==", "!=", ">", "<", ">=", "<=", "&&",
"||", "!", "&", "|", "^", "~", "<<", ">>"};
const int numOperators = sizeof(operators) / sizeof(operators[0]);
// Function to check if a string is an operator
int isOperator(const char *token) {
    int i;
    for ( i = 0; i < numOperators; i++) {
        if (strcmp(token, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
// Function to tokenize the input and validate operators
void tokenizeAndValidate(char *input) {
    char token[MAX_TOKEN_LENGTH];
    int i = 0, tokenIndex = 0;
    while (input[i] != '\0') {
        // Skip white spaces
        if (isspace(input[i])) {
            i++;
            continue;
        }
        // Extract token
        tokenIndex = 0;
        while (!isspace(input[i]) && input[i] != '\0') {
            token[tokenIndex++] = input[i++];
        }
        token[tokenIndex] = '\0';
        // Validate token
        if (isOperator(token)) {
            printf("Valid operator: %s\n", token);
        }
        else {
            printf("Invalid operator: %s\n", token);
        }
    }
}
int main() {
    char input[MAX_TOKEN_LENGTH];
    // Read input from user
    printf("Enter a string to tokenize and validate operators: ");
    fgets(input, MAX_TOKEN_LENGTH, stdin);
    // Remove newline character from the input if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    // Tokenize and validate input
    tokenizeAndValidate(input);
    return 0;
}