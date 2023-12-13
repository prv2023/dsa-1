#include <stdio.h>
#include <stdlib.h>
int queue[100];
int front=-1;
int rear=0;

int isFull(){
    if(rear==99){
        return 1;
    }else{return 0;}
}
int isEmpty(){
    if(front==-1 || rear<front){
        return 1;
    }else{return 0;}
}

void enqueue(int data){
    
    if(isFull()==1){printf("Overflow!");}else if(isEmpty()==1){
        front++;
        queue[rear]=data;
    }
    else{
        rear++;
        queue[rear]=data;
    }
}
void dequeue(){
    if(isEmpty()==1){
        printf("Underflow!");
    }else{
        
        printf("Popped %d\t", queue[front]);
        front++;
    }
}

void peek(){
    if(isEmpty()==1){printf("QUeue is empty");}
    else{
        printf("%d", queue[front]);
    }
}

void main(){
    int data;

    printf("Enter an element to enqueue: ");
    scanf("%d", &data);
    enqueue(data);

    // Rest of the code


peek();
dequeue();
peek();
}