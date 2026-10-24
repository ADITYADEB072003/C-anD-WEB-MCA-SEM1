#include <stdio.h>

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    char *start = str;
    char *end = str;

    while (*end != '\0') end++;
    end--;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    printf("Reversed String: %s\n", str);
    return 0;
}