#include <stdio.h>
#define PI 3.14159
#define MAX 10
int main(){
    char str[100];
    int length=0;
    int i ;
    int palindrome=1;

    printf("Enter the string \n");
    scanf("%s",str);
    
    while(str[length]!='\0'){
        length++;
    }
    printf("Lenght %d",length);
    for(i=0;i<length/2;i++){
        if(str[i]!=str[length-1-i]){
            palindrome=0;
            break;
        }
    }
if (palindrome) {
        printf("\"%s\" is a Palindrome.\n", str);
    } else {
        printf("\"%s\" is NOT a Palindrome.\n", str);
    }

}