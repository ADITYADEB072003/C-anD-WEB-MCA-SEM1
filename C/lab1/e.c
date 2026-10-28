#include <stdio.h>

int stack[5], top = -1;

void push(int val){
    if (top == 4) printf("Overflow\n");
    else stack[++top] = val;
}

void pop(){
    if (top == -1) printf("Underflow\n");
    else printf("Popped = %d\n", stack[top--]);
}

void display(){
    for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

int main(){
    push(10);
    push(20);
   
    pop();
    display();
    return 0;
}