#include <stdio.h>
#include <string.h>

enum states { Q0, Q1, Q2, Q3, Q4, Q5 };

int main() {
    char input[100];
    printf("Enter a string of a's and b's: ");
    scanf("%s", input);

    int currentState = Q0;
    for (int i = 0; i < strlen(input); i++) {
        char symbol = input[i];
        switch (currentState) {
            case Q0:
                if (symbol == 'a') {
                    currentState = Q1;
                } else {
                    printf("Rejected: String must start with 'a'.\n");
                    return 1;
                }
                break;
            case Q1:
                if (symbol == 'b') {
                    currentState = Q2;
                } else {
                    printf("Rejected: Second symbol must be 'b'.\n");
                    return 1;
                }
                break;
            case Q2:
                if (symbol == 'a') {
                    currentState = Q3;
                } else if (symbol == 'b') {
                    currentState = Q4;
                } else {
                    printf("Rejected: Third symbol must be 'a' or 'b'.\n");
                    return 1;
                }
                break;
            case Q3:
                if (symbol == 'a' || symbol == 'b') {
                    currentState = Q5;
                } else {
                    printf("Rejected: Fourth symbol must be 'a' or 'b'.\n");
                    return 1;
                }
                break;
            case Q4:
                if (symbol == 'a') {
                    currentState = Q3;
                } else {
                    printf("Rejected: Fifth symbol must be 'a'.\n");
                    return 1;
                }
                break;
            case Q5:
                if (symbol != 'a' && symbol != 'b') {
                    printf("Rejected: Only 'a' or 'b' allowed after 'ab*a*'.\n");
                    return 1;
                }
                break;
        }
    }

    if (currentState == Q5) {
        printf("Accepted: String matches the DFA.\n");
    } else {
        printf("Rejected: String does not match the DFA.\n");
    }

    return 0;
}
