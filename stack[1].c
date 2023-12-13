#include <stdio.h>
#include <stdlib.h>
int top1(int stack[]){
    int i=0;
    while(i<100){
        if(stack[i]==-1){
           
            return i-1;
        }
        i++;
    }
    return -2;
}
void push(int stack[],int data){
     int top=top1(stack);
     printf(".");
    if(top==100){printf("Overflow!");}
    else{
        top++;
    stack[top]=data;
}}
void pop(int stack[]){
     int top=top1(stack);
    if(top<=0){printf("Underflow!");}else{
        printf("%d", stack[top]);
    stack[top--]=-1;
}}
int peek(int stack[]){
    int top=top1(stack);
    if(top<0){
        printf("Stack is empty"); return -1;
    }else {return stack[top];}
} 

void main(){
    int stack[100];
    for(int i=0;i<100;i++){stack[i]=-1;}
    int choice=1;
    int data;
    
    printf("Enter the values to push into the stack (-1 to stop):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        push(stack, data);
    }
    
    pop(stack);
    peek(stack);
    printf("%d",peek(stack));
}
