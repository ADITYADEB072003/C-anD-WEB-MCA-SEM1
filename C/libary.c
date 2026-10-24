#include <stdio.h>
#include <string.h>

#define MAX 100
#define FINE_PER_DAY 5

struct Book {
    int id, issued;
    char title[50], author[50];
    int issueDay, issueMonth, issueYear;
    int dueDay, dueMonth, dueYear;
};

struct Book books[MAX];
int total = 0;

// Function declarations
void addBook();
void searchBook();
void borrowBook();
void returnBook();
void displayBooks();
void countIssuedBooks();
int leapYear(int year);
int validDate(int d, int m, int y);
int totalDays(int d, int m, int y);

int main() {
    int choice;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book and Calculate Fine\n");
        printf("5. Display Available Books\n");
        printf("6. Count Issued Books\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                searchBook();
                break;

            case 3:
                borrowBook();
                break;

            case 4:
                returnBook();
                break;

            case 5:
                displayBooks();
                break;

            case 6:
                countIssuedBooks();
                break;

            case 7:
                printf("Exiting Library System...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}

// Check whether a year is a leap year
int leapYear(int year) {
    return year % 400 == 0 ||
           (year % 4 == 0 && year % 100 != 0);
}

// Validate a date
int validDate(int d, int m, int y) {
    int days[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (y < 1 || m < 1 || m > 12 || d < 1)
        return 0;

    if (leapYear(y))
        days[1] = 29;

    return d <= days[m - 1];
}

// Convert a date into total days
int totalDays(int d, int m, int y) {
    int days = 0;

    int monthDays[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    for (int i = 1; i < y; i++) {
        if (leapYear(i))
            days += 366;
        else
            days += 365;
    }

    for (int i = 1; i < m; i++) {
        if (i == 2 && leapYear(y))
            days += 29;
        else
            days += monthDays[i - 1];
    }

    return days + d;
}

// Add a new book
void addBook() {
    int id;

    if (total >= MAX) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &id);

    // Check for duplicate Book ID
    for (int i = 0; i < total; i++) {
        if (books[i].id == id) {
            printf("Book ID already exists! Try another ID.\n");
            return;
        }
    }

    books[total].id = id;

    printf("Enter Book Title: ");
    scanf(" %49[^\n]", books[total].title);

    printf("Enter Author Name: ");
    scanf(" %49[^\n]", books[total].author);

    books[total].issued = 0;

    total++;

    printf("Book added successfully!\n");
}

// Search for a book by title or author
void searchBook() {
    char search[50];
    int found = 0;

    printf("Enter title or author to search: ");
    scanf(" %49[^\n]", search);

    for (int i = 0; i < total; i++) {
        if (strstr(books[i].title, search) != NULL ||
            strstr(books[i].author, search) != NULL) {

            printf("\nBook ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);

            if (books[i].issued)
                printf("Status: Issued\n");
            else
                printf("Status: Available\n");

            found = 1;
        }
    }

    if (!found)
        printf("Book not found!\n");
}

// Borrow a book
void borrowBook() {
    int id, d, m, y;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (books[i].id == id) {

            if (books[i].issued) {
                printf("Book is already issued!\n");
                return;
            }

            printf("Enter issue date (DD MM YYYY): ");
            scanf("%d %d %d", &d, &m, &y);

            if (!validDate(d, m, y)) {
                printf("Invalid issue date!\n");
                return;
            }

            printf("Enter due date (DD MM YYYY): ");
            scanf("%d %d %d",
                  &books[i].dueDay,
                  &books[i].dueMonth,
                  &books[i].dueYear);

            if (!validDate(books[i].dueDay,
                           books[i].dueMonth,
                           books[i].dueYear) ||
                totalDays(books[i].dueDay,
                          books[i].dueMonth,
                          books[i].dueYear) <= totalDays(d, m, y)) {

                printf("Invalid due date!\n");
                return;
            }

            books[i].issueDay = d;
            books[i].issueMonth = m;
            books[i].issueYear = y;

            books[i].issued = 1;

            printf("Book borrowed successfully!\n");
            return;
        }
    }

    printf("Book not found!\n");
}

// Return a book and calculate the fine
void returnBook() {
    int id, d, m, y;
    int lateDays, fine;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (books[i].id == id) {

            if (!books[i].issued) {
                printf("Book is not currently issued!\n");
                return;
            }

            printf("Enter return date (DD MM YYYY): ");
            scanf("%d %d %d", &d, &m, &y);

            if (!validDate(d, m, y) ||
                totalDays(d, m, y) <
                totalDays(books[i].issueDay,
                          books[i].issueMonth,
                          books[i].issueYear)) {

                printf("Invalid return date!\n");
                return;
            }

            lateDays = totalDays(d, m, y) -
                       totalDays(books[i].dueDay,
                                 books[i].dueMonth,
                                 books[i].dueYear);

            if (lateDays < 0)
                lateDays = 0;

            fine = lateDays * FINE_PER_DAY;

            printf("\nLate Days: %d\n", lateDays);
            printf("Fine: Rs. %d\n", fine);

            books[i].issued = 0;

            printf("Book returned successfully!\n");
            return;
        }
    }

    printf("Book not found!\n");
}

// Display all available books
void displayBooks() {
    int found = 0;

    printf("\n===== AVAILABLE BOOKS =====\n");

    for (int i = 0; i < total; i++) {
        if (!books[i].issued) {
            printf("ID: %d | Title: %s | Author: %s\n",
                   books[i].id,
                   books[i].title,
                   books[i].author);

            found = 1;
        }
    }

    if (!found)
        printf("No available books!\n");
}

// Count the number of issued books
void countIssuedBooks() {
    int count = 0;

    for (int i = 0; i < total; i++) {
        if (books[i].issued)
            count++;
    }

    printf("Total issued books: %d\n", count);
}