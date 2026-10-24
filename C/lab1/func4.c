#include <stdio.h>

void printEvens(int start, int end) {
  if (start > end)
    return;
  if (start % 2 == 0)
    printf("%d ", start);
  printEvens(start + 1, end);
}

void printOdds(int start, int end) {
  if (start > end)
    return;
  if (start % 2 != 0)
    printf("%d ", start);
  printOdds(start + 1, end);
}

int main() {
  printf("Evens (1 to 10): ");
  printEvens(1, 10);

  printf("\nOdds (1 to 10): ");
  printOdds(1, 10);
  printf("\n");

  return 0;
}