#include <stdio.h>

int main() {
    char str[100], sub[100];
    int start, length, i;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter starting position: ");
    scanf("%d", &start);

    printf("Enter length of substring: ");
    scanf("%d", &length);

    for (i = 0; i < length; i++) {
        sub[i] = str[start + i];
    }

    sub[i] = '\0';

    printf("Substring: %s\n", sub);

    return 0;
}