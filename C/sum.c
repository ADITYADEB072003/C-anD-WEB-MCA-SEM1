#include <stdio.h>

int main()
{
    int i, j;
    // Outer loop for the 5 rows
    for(i = 1; i <= 5; i++)
    {
        // First inner loop: Print increasing numbers
        // Starts from the current row value and ends at (2*i - 1)
        for(j = i; j <= 2*i - 1; j++)
        {
            printf("%d", j);
        }
        // Second inner loop: Print decreasing numbers
        // Starts from (2*i - 2) and goes down back to the row value
        for(j = 2*i - 2; j >= i; j--)
        {
           
            printf("%d", j);
        }
        // Move to a new line after each row is printed
        printf("\n");
    }
    return 0; // Indicate successful program execution
}