#include <stdio.h>

int main() {
    char str[100], sub[100];
    int i, j, found = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter substring to find: ");
    scanf("%s", sub);

    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; sub[j] != '\0'; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }

        if (sub[j] == '\0') {
            found = 1;
            printf("Substring found at index %d\n", i);
            break;
        }
    }

    if (found == 0) {
        printf("Substring not found\n");
    }

    return 0;
}