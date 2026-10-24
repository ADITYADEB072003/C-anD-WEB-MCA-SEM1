#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;

    // 1. Access array elements using a pointer
    printf("First element: %d\n", *p);
    printf("Second element: %d\n", *(p + 1));
int sum=0;
    // 2. Print the entire array using a pointer
    printf("Array elements: ");
    for (int i = 0; i < 5; i++){
        printf("%d ", *(p + i));
        sum+=*p;
        p++;
    ;}
    printf("\nSum of array elements: %d\n", sum);


    // 3. Modify an array element using a pointer
    *(p + 2) = 100;
    printf("\nModified third element: %d\n", arr[2]);

    // 4. Move the pointer to the next element
    p++;
    printf("After p++: %d\n", *p);

    // 5. Array of pointers
    int a = 5, b = 10, c = 15;
    int *ptr[3] = {&a, &b, &c};

    printf("Array of pointers: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", *ptr[i]);

    return 0;
}