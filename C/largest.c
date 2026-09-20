

#include <stdio.h>

int main()
{
    int a[5] = {1,1, 2, 3, 4, 5};

    int largest = a[0];
    int smallest = a[0];
    int i,j;

    int size = sizeof(a) / sizeof(a[0]);

for(i=0;i<size;i++){
    for (j=i+1;j<size;j++){
        if(a[i]==a[j]){
            for(int k=j;k<size-1;k++){
                a[k]=a[k+1];
            }
            size--;
            j--;
        }
    }
}










    // Find largest
    for (int i = 0; i < size; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }

    // Find smallest
    for (int i = 0; i < size; i++)
    {
        if (a[i] < smallest)
        {
            smallest = a[i];
        }
    }

    // Find second largest
    int secondlargest = a[0];

    for (int i = 0; i < size; i++)
    {
        if (a[i] > secondlargest && a[i] != largest)
        {
            secondlargest = a[i];
        }
    }

    // Find second smallest
    int secondsmallest = a[0];

    for (int i = 0; i < size; i++)
    {
        if (a[i] < secondsmallest && a[i] != smallest)
        {
            secondsmallest = a[i];
        }
    }

    printf("%d\n", largest);
    printf("%d\n", secondlargest);
    printf("%d\n", smallest);
    printf("%d\n", secondsmallest);

    return 0;
}