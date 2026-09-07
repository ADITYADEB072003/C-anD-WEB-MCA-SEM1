#include <stdio.h>

int main() {
    int matrix[3][3], max[3][3], multiply[3][3];
    int su[3][3];
    int row, col, i, j, k;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &row, &col);

    if (row != col) {
        printf("Matrix multiplication is not possible for non-square matrices.\n");
        return 0;
    }

    printf("Enter the elements of the first matrix:\n");

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Matrix multiplication
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            multiply[i][j] = 0;

            for (k = 0; k < col; k++) {
                multiply[i][j] += matrix[i][k] * max[k][j];
            }
        }
    }

    // Matrix addition
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            su[i][j] = matrix[i][j] + max[i][j];
        }
    }

    printf("\nResultant matrix after multiplication:\n");

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", multiply[i][j]);
        }
        printf("\n");
    }

    printf("\nResultant matrix after addition:\n");

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", su[i][j]);
        }
        printf("\n");
    }

    return 0;
}