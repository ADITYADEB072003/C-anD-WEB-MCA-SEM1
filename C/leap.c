#include <stdio.h>
int leap(int n){
    if(n%4==0){
        if (n%100==0){
            if(n%400==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
            return 0;
        }
    }
int leap2(int n){
    if((n%400==0)|| (n%4==0 &&n%100!=0)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    printf("Enter a year: ");
    scanf("%d",&n);
    if(leap(n)&&leap2(n)){
        printf("%d is a leap year.",n);
    }
    else{
        printf("%d is not a leap year.",n);
    }
}