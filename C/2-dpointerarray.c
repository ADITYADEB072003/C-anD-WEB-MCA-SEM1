#include <stdio.h>

int main()
{
    int mat[2][2] = {{12, 22}, {33, 44}};
    int (*p)[2] = mat;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }

    return 0;
}