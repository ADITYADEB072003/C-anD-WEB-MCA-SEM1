#include <stdio.h>
#include <stdlib.h> // Header file required for malloc, calloc, and free

int main() {
    int n = 5;
    int *malloc_arr;
    int *calloc_arr;

    printf("==========================================\n");
    printf("1. DEMONSTRATION OF MALLOC()\n");
    printf("==========================================\n");

    // Allocate memory for 'n' integers using malloc()
    malloc_arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (malloc_arr == NULL) {
        printf("Memory allocation using malloc failed!\n");
        return 1;
    }
    printf("Memory successfully allocated using malloc().\n");

    // Display initial values in malloc_arr before manual initialization (garbage values)
    printf("Initial values in malloc block (garbage values):\n");
    for (int i = 0; i < n; i++) {
        printf("malloc_arr[%d] = %d\n", i, malloc_arr[i]);
    }

    // Assigning values to the allocated memory
    for (int i = 0; i < n; i++) {
        malloc_arr[i] = (i + 1) * 10;
    }

    // Displaying assigned values
    printf("\nAssigned values in malloc block:\n");
    for (int i = 0; i < n; i++) {
        printf("malloc_arr[%d] = %d\n", i, malloc_arr[i]);
    }

    // Deallocate malloc memory
    free(malloc_arr);
    malloc_arr = NULL; // Good practice to set pointer to NULL after freeing
    printf("Memory allocated by malloc() successfully freed.\n\n");

    printf("==========================================\n");
    printf("2. DEMONSTRATION OF CALLOC()\n");
    printf("==========================================\n");

    // Allocate memory for 'n' integers using calloc()
    calloc_arr = (int *)calloc(n, sizeof(int));

    // Check if memory allocation was successful
    if (calloc_arr == NULL) {
        printf("Memory allocation using calloc failed!\n");
        return 1;
    }
    printf("Memory successfully allocated using calloc().\n");

    // Display initial values in calloc_arr (initialized to 0 automatically)
    printf("Initial values in calloc block (automatically initialized to 0):\n");
    for (int i = 0; i < n; i++) {
        printf("calloc_arr[%d] = %d\n", i, calloc_arr[i]);
    }

    // Assigning values to the allocated memory
    for (int i = 0; i < n; i++) {
        calloc_arr[i] = (i + 1) * 100;
    }

    // Displaying assigned values
    printf("\nAssigned values in calloc block:\n");
    for (int i = 0; i < n; i++) {
        printf("calloc_arr[%d] = %d\n", i, calloc_arr[i]);
    }

    // Deallocate calloc memory
    free(calloc_arr);
    calloc_arr = NULL; // Good practice to set pointer to NULL after freeing
    printf("Memory allocated by calloc() successfully freed.\n");

    return 0;
}
