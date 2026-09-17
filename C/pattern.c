#include <stdio.h>
int main() {
    int num, i, j,isPrime = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    for(i=0;i<num;i++){
         for (j = 0; j < num - i - 1; j++) {
            printf("");
        }
        for(j=0;j<=i;j++){
            printf("%d", j);
            }
            printf("\n");
        }
        
    }
