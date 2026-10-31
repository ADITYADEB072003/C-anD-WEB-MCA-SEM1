#include <stdio.h>
#define PI 3.14159
#define MAX 10
int main(){
    
int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int r1, c1, r2, c2, i, j, k;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
if(c1!=r2){
    printf("Error: Matrix multiplication impossible! Columns of A (%d) must equal Rows of B (%d).\n", c1, r2);
    return 0;
}
    printf("\nEnter elements for Matrix A (%dx%d):\n", r1, c1);
for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
        scanf("%d",&A[i][j]);
    }
}
printf("\nEnter elements for Matrix B (%dx%d):\n", r2, c2);
for(i=0;i<r2;i++){
    for(j=0;j<c2;j++){
        scanf("%d",&B[i][j]);
    }}
for(i=0;i<r1;i++){
    for(j=0;j<c2;j++){
        C[i][j]=0;
        for(k=0;k<c1;k++){
            C[i][j]+=A[i][k]*B[k][j];
        }
    }
}
printf("\nEnter elements for Matrix C (%dx%d):\n", r2, c2);
for(i=0;i<r1;i++){
    for(j=0;j<c2;j++){
        printf("%d",C[i][j]);
    }
    printf("\n");
}

}