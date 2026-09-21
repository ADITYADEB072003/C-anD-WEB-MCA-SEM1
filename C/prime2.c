#include <stdio.h>

int main() {
    int i, count;

    for (int j = 2; j <= 10; j++) {
        count = 0;

        for (i = 2; i <= j / 2; i++) {
            if (j % i == 0) {
                count++;
                break;
            }
        }

        if (count == 0) {
            printf("%d is a prime number.\n", j);
        }
    }

    return 0;
}