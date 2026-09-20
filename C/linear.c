#include <stdio.h>

int main()
{
    int arr[5], i, j, target;
    int low = 0, high, mid;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
        scanf("%d", &arr[i]);
int k=0;
int count=0;
for(;arr[k]!='\0';k++){
    count++;
}
high=count;
printf("Count =%d",count);

    // Sort the array
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    // Binary Search
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == target)
        {
            printf("Element found at index %d", mid);
            return 0;
        }
        else if(target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Element not found");

    return 0;
}