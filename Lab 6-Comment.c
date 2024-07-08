/*Write a C program to identify wheather a given line is a comment or not */

/* logic
1. Read the input string.
2. Check wheather the string is starting '/' and check next character is '/'or '*'
3. If condition satisfies print comment.
4. Else not a comment. */

#include <stdio.h>
#include <string.h>

void main() {
    char comment[100];
    int i = 2, a = 0;
    
    printf("Enter a comment: ");
    fgets(comment, sizeof(comment), stdin); // Use fgets to read the whole line

    if (comment[0] == '/') {
        if (comment[1] == '/') {
            printf("It is a comments");
        } else if (comment[1] == '*') {
            for (i = 2; i < strlen(comment) - 1; i++) {
                if (comment[i] == '*' && comment[i + 1] == '/') {
                    printf("It is a comments");
                    a = 1;
                    break;
                }
            }
            if (!a) {
                printf("It is not a comment");
            }
        } else {
            printf("It is not a comment");
        }
    } else {
        printf("It is not a comment");
    }
}
