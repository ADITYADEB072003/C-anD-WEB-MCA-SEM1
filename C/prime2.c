#include <stdio.h>
int main(){
    int i,flag;
    
    for(int j=2;j<=10;j++){
        flag=0;
    for(i=2;i<=j/2;i++){
        if (j%i==0){
            flag=1;
            break;
        }
    }
    if (j==1){
        printf("1 is neither prime nor composite.");
    }
    else{
        if (flag==0)
            printf("%d is a prime number.\n",j);
       
    }
}
}