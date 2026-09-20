#include <stdio.h>
long int fact = 1;
int main() {
  extern long int fact;
  int arr[5] = {1, 3, 4};
  for (int i = 0; i < 5; i++) {
    printf("%d \n", arr[i]);
  }
   register int j = 0;
  for (j = 0; j <= 5; j++);
  printf("  Value=%d \n \t", j);
  long int n;
  printf("enter the no");
  scanf("%ld", &n);
  for (long int i = 1; i <= n; i++) {
    fact *= i;
  }
  printf("The Factorial of %ld is = %ld \n", n, fact);
  char arr1[] = {"abcd"};
  int k = 0;
  int count = 0;
  for (; arr1[k] != '\0'; k++) {
    count++;
  }
  printf("Count =%d", count);
}