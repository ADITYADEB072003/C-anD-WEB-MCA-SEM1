void printOdds(int start, int end) {
  if (start > end)
    return;
  if (start % 2 != 0)
    printf("%d ", start);
  printOdds(start + 1, end);
}