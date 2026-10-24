#include <stdio.h>
int fact(int x){
    if (x==0||x==1){
        return 1;
    }else{
        return x*fact(x-1)
;    }
}
int fibonacci(int n){
   if(n==0||n==1){
       return 1;
   }
   return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Factorial of %d is %d\n",n,fact(n));
    for(int i=0;i<n;i++){
        printf("Fibonacci of %d is %d\n",i,fibonacci(i));
    }
    return 0;
}