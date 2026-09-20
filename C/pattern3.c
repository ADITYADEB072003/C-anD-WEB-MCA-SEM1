#include <stdio.h>
int main()
{
int i, j;
for (i = 1; i <= 4; i++)
{
for (j = 1; j <= 5; j++)
{
if (j == 2)
continue;
if (i + j > 6)
break;
printf("%d%d ", i, j);
}
}
printf("\n");
return 0;
}