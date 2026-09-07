#include <stdio.h>

int main() {
    int arr[5];
    int a[5];
    int i, j, k = 0;
    int found;

    printf("Enter 5 elements:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");

    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    // Remove duplicates
    for (i = 0; i < 5; i++) {
        found = 0;

        for (j = 0; j < k; j++) {
            if (arr[i] == a[j]) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            a[k] = arr[i];
            k++;
        }
    }

    printf("\nArray after removing duplicates:\n");

    for (i = 0; i < k; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}