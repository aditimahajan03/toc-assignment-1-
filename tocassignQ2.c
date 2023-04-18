#include <stdio.h>
#include <string.h>

int main() {
    char input[101];
    int state = 0, i = 0;

    printf("Enter input string: ");
    scanf("%s", input);

    while (input[i] != '\0') {
        switch (state) {
            case 0:
                if (input[i] == '1') {
                    state = 1;
                } else {
                    printf("String rejected\n");
                    return 0;
                }
                break;
            case 1:
                if (input[i] == '0') {
                    state = 2;
                } else if (input[i] == '1') {
                    state = 1;
                } else {
                    printf("String rejected\n");
                    return 0;
                }
                break;
            case 2:
                if (input[i] == '0' || input[i] == '1') {
                    state = 2;
                } else if (input[i] == '1') {
                    state = 3;
                } else {
                    printf("String rejected\n");
                    return 0;
                }
                break;
            case 3:
                if (input[i] == '0' || input[i] == '1') {
                    state = 3;
                } else {
                    printf("String rejected\n");
                    return 0;
                }
                break;
        }
        i++;
    }

    if (state == 1 || state == 2) {
        printf("String accepted\n");
    } else {
        printf("String rejected\n");
    }

    return 0;
}







