#include <stdio.h>
int main(){
    int a=121;
    int sum=0;
    int b=a;
    int reverse=0;
    // while(a!=0){
    //     int digit=a%10;
    //     reverse=reverse*10+digit;
    //     sum+=digit;
    //     a=a/10;
    // }
    for(;a!=0;a=a/10){
         int digit=a%10;
        reverse=reverse*10+digit;
        sum+=digit;
    }
    printf("%d \n",reverse);
     printf("%d \n",sum);
    if(b==reverse){
        printf("Palindrome");
    }
    else{
        printf("Not a palindrome");
    }
}