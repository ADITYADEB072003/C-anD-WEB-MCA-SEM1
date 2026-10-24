#include <stdio.h>

int main() {
    char str1[100], str2[50];
    int i, j, flag = 0;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // Compare two strings
    for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

    // Concatenate two strings
    for (i = 0; str1[i] != '\0'; i++);

    for (j = 0; str2[j] != '\0'; j++) {
        str1[i] = str2[j];
        i++;
    }

    str1[i] = '\0';

    printf("Concatenated string: %s\n", str1);

    return 0;
}