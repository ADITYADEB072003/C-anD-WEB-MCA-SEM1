#include <stdio.h>
int main() {
    char *name[4] = { "New Zealand", "Australia", "India" };
    printf("The countries are:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", name[i]);    }

}