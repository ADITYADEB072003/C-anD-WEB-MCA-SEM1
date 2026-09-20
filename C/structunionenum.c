#include <stdio.h>

typedef enum {
    MALE = 1,
    FEMALE = 2
} Gender;

typedef struct {
    int id;
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

    // Structure
    Student s = {101, "Aditya", MALE};

    // Union
    Result r;
    r.marks = 90;

    printf("Array: ");
    for(int i = 0; i < 3; i++)
        printf("%d ", a[i]);

    printf("\nPointer: %d", *p);

    printf("\n\nStructure:");
    printf("\nID = %d", s.id);
    printf("\nName = %s", s.name);
    printf("\nGender = %d", s.gender);

    printf("\n\nUnion marks = %d", r.marks);

    return 0;
}