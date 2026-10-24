#include <stdio.h>

void swapValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swapRef(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 5, y = 10;

    swapValue(x, y);
    printf("Call by Value: x = %d, y = %d\n", x, y);

    swapRef(&x, &y);
    printf("Call by Reference: x = %d, y = %d\n", x, y);

    return 0;
}