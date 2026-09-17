#include <stdio.h>
# 
int main(){
    int a[3][3]={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int i, j;
    printf("The diagonal elements of the matrix are:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i==j)
                printf("%d ", a[i][j]);
            
        }
    }
    printf("\nThe elements above the diagonal are:\n");
    for(i=0;i<3;i++){
        for(j=i+1;j<3;j++){
            
                printf("%d ", a[i][j]);
            
        }
    }
    printf("\nThe elements below the diagonal are:\n");
    for(i=1;i<3;i++){
        for(j=0;j<i;j++){
            
                printf("%d ", a[i][j]);
            
        }
    }
    printf("\nThe sum of the diagonal elements is:\n");
    int temp=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            temp+=a[i][j]; }
                temp+=a[i][j]; }
        }
