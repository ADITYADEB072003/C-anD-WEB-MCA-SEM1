#include <stdio.h>
int main(){
    int i,j;
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    for(i=0;str[i]!='\0';i++){
        for(j=0;j<i;j++){
            if(str[i]==str[j]){
                break;
            }
        }
        if(i==j){
            printf("%c",str[i]);
        }

    }
}