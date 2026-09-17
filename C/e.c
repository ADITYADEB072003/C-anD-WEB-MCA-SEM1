#include <stdio.h>

int main() {
    int a = 10, b = 3, c = 2;
    int x;

    x = a + b * c > 10 && a % b == 1;

    printf("%d\n", x);

    return 0;
}