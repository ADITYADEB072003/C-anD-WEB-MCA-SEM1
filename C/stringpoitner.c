
#include <stdio.h>

int main() {
    char str[100];
    char *ptr = str;

    printf("Enter a string: ");
    scanf("%99s", str);

    printf("The entered string is: %s\n", ptr);

    int count = 0;

    while (*ptr != '\0') {
        count++;
        ptr++;
    }

    printf("The length of the string is: %d\n", count);

    ptr = str;

    printf("The characters of the string are:\n");

    while (*ptr != '\0') {
        printf("%c\n", *ptr);
        ptr++;
    }

    return 0;
}
