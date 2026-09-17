#include <stdio.h>

int main()
{
    int n, i, count = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for(i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            count++;
            break;
        }
    }

    if(n == 1)
    {
        printf("1 is neither prime nor composite.");
    }
    else if(count == 2)
    {
        printf("%d is not a prime number.", n);
    }
    else
    {
        printf("%d is a prime number.", n);
    }

    return 0;
}