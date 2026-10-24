#include <stdio.h>

int main() {
    char str[100], ch;
    int i, found = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter character to find: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            printf("Character found at index %d\n", i);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Character not found\n");
    }

    return 0;
}