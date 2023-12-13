#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1))
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("%d enqueued successfully.\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return;
    }
    int data = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
    printf("%d dequeued successfully.\n", data);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    enqueue(-2);
    int data;
    printf("Enter the element to enqueue: ");
    scanf("%d", &data);
    enqueue(data);

    display();
    dequeue();
    display();

    printf("Enter the element to enqueue: ");
    scanf("%d", &data);
    enqueue(data);

    // Rest of the code...
    display();
    return 0;
}