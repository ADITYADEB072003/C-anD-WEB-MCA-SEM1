
#include <stdio.h>

char queue[100];
int front = -1, rear = -1;char arr[100];
int count=0;
void enqueue(char value) {
    if (rear >= 99) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    queue[++rear] = value;
    printf("Enqueued %c into the queue\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    
    printf("Dequeued %c from the queue\n", queue[front++]);

    if (front > rear) {
        front = rear = -1;
    }
}


void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");

    for (int i = rear; i >= front; i--) {
         arr[++count]=queue[i];
        printf("%c\n", queue[i]);
       
    }
}
void displayArray() {
    printf("Dequeued elements stored in array:\n");

    for (int i = 0; i < count; i++) {
        printf("%c ", arr[i]);
    }

    printf("\n");
}

int main() {
    char n[100];

    printf("Enter a string: ");
    scanf("%99s", n);

    for (int i = 0; n[i] != '\0'; i++) {
        enqueue(n[i]);
    }

    display();

    dequeue();
    dequeue();

    display();
    displayArray();

    return 0;
}