#include<stdio.h>
int main(){
    int i=1;int n=10;
    int a=0,b=1;
    int c;
    for(;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
        printf("%d \n",a);
    }
    
}
