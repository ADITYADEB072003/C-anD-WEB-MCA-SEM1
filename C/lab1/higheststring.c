#include <stdio.h>

int main(void) {
    char str[100];
    char highest = '\0';
    int maxcount = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        int count = 0;
        for (int j = 0; str[j] != '\0' && str[j] != '\n'; j++) {
            if (str[i] == str[j]) {
                count++;
            }
        }

        if (count > maxcount) {
            maxcount = count;
            highest = str[i];
        }
    }

    if (maxcount == 0) {
        printf("The string is empty.\n");
    } else {
        printf("The highest character in the string is: %c %d\n", highest, maxcount);
    }

    return 0;
}