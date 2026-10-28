#include <stdio.h>
int stack[100], top = -1;
void push(char value) {
    if (top >= 99) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
    printf("Pushed %c onto the stack\n", value);
}
void pop(){
    if(top<0){
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped %c from the stack\n",stack[top--]);
}
void display(){
    if(top<0){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for(int i=top;i>=0;i--){
        printf("%c\n",stack[i]);
    }
}
int main(){
    int i,j;
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    for(i=0;str[i]!='\0';i++){
        push(str[i]);
    }
    display();
    
        pop();
        pop();
        display();
    
    return 0;}