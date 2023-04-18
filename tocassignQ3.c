#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int state = 0, i = 0;

    printf("Enter the input string: ");
    scanf("%s", str);

    while (str[i] != '\0')
    {
        if (state == 0 && str[i] == 'a')
            state = 1;
        else if (state == 0 && str[i] == 'b')
            state = 2;
        else if (state == 1 && str[i] == 'a')
            state = 0;
        else if (state == 1 && str[i] == 'b')
            state = 3;
        else if (state == 2 && str[i] == 'a')
            state = 3;
        else if (state == 2 && str[i] == 'b')
            state = 0;
        else if (state == 3 && str[i] == 'a')
            state = 2;
        else if (state == 3 && str[i] == 'b')
            state = 1;
        i++;
    }

    if (state == 0 || state == 1)
        printf("Accepted");
    else
        printf("Rejected");

    return 0;
}
