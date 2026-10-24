
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    int age;
} Student;

int main() {
    // Array of 3 structures
    Student s[3];
    int i;

    // Input student details
    for (i = 0; i < 3; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter name: ");
        scanf("%19s", s[i].name);

        printf("Enter age: ");
        scanf("%d", &s[i].age);
    }

    // Display student details
    printf("\n--- Student Details ---\n");

    for (i = 0; i < 3; i++) {
        printf("\nID: %d", s[i].id);
        printf("\nName: %s", s[i].name);
        printf("\nAge: %d\n", s[i].age);
    }

    return 0;
}
