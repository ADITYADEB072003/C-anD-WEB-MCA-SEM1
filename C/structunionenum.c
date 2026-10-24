
#include <stdio.h>
#include <string.h>

typedef enum {
    MALE = 1,
    FEMALE = 2
} Gender;

typedef struct {
    int id;
    int age[3];
    char name[20];
    Gender gender;
} Student;

typedef union {
    int marks;
    float percentage;
} Result;

int main()
{
    // Array
    int a[3] = {10, 20, 30};

    // Pointer
    int *p = a;

    // Array of 20 structures
    Student s[20];

    // Access the first student's members using s[0]
    s[0].id = 1;

    strcpy(s[0].name, "John Doe");

    // Input 3 ages for the first student
    for (int i = 0; i < 3; i++) {
        printf("Enter age %d: ", i + 1);
        scanf("%d", &s[0].age[i]);
    }

    s[0].gender = MALE;

    // Union
    Result r;
    r.marks = 90;

    // Display array
    printf("\nArray: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", a[i]);

    // Display pointer value
    printf("\nPointer: %d", *p);

    // Display first student's details
    printf("\n\nStructure:");
    printf("\nID = %d", s[0].id);
    printf("\nName = %s", s[0].name);
    printf("\nGender = %d", s[0].gender);

    printf("\nAges: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", s[0].age[i]);

    // Display union
    printf("\n\nUnion marks = %d\n", r.marks);

    return 0;
}
