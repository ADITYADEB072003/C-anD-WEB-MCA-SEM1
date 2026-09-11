#include <stdio.h>
int main(){
    int i,j;
        for (i=1;i<10;i++){
            printf("%d ->>>",i);
            for(j=0;j<10-i;j++){
                printf(" ");
            }
            printf("\t");
            for (j=1;j<i;j++){
                printf("%d ",i+j);
            }
            printf("\n");
        }
}