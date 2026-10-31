#include <stdio.h>
#define PI 3.14159
#define MAX 10
void reverstring(char *str){
    char *start=str;
    char *end=str;
    char temp;
    if(str==NULL || *str=='\0') return ;

    while(*end!='\0'){
        end++;
    }
    end--;
    while(start<end){
        temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
}
int main(){
    char str[100];
    char sub[100];
    int length=0;
    int i,j ;
    int palindrome=1,found=0;

    printf("Enter the string \n");
    scanf("%s",str);
       printf("Enter the substring \n");
    scanf("%s",sub);
    printf("Original String: %s\n", str);
    reverstring(str);
    printf("Reversed String: %s\n", str);

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

for(i=0;str[i]!='\0';i++){
    j=0;
    while(sub[j]!='\0'&& str[i+j]==sub[j]){
        j++;
    }
    if(sub[j]=='\0'){
        found=1;
        break;
    }
}
if (found) {
        printf("Substring found");
    } else {
        printf("Substring not found");
    }
}