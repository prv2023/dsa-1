# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
struct Stack {
int data;
struct Stack* next;
};
int isEmpty(struct Stack* top) {
return (top == NULL);
}
struct Stack* push(struct Stack* top, int value) {
struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
newNode->data = value;
newNode->next = top;
return newNode;
}
struct Stack* pop(struct Stack* top) {
if (isEmpty(top)) {
printf("Stack is empty.\n");
return NULL;
}
struct Stack* temp = top;
top = top->next;
free(temp);
return top;
}
int evaluatePrefixExpression(char prefix[]) {
struct Stack* stack = NULL;
int length = strlen(prefix);
for (int i = length - 1; i >= 0; i--) {
if (isdigit(prefix[i])) {
stack = push(stack, prefix[i] - '0');
} else {
int operand1, operand2;
if (!isEmpty(stack))
operand1 = stack->data;
else {
printf("Invalid expression.\n");
exit(1);
}
stack = pop(stack);
if (!isEmpty(stack))
operand2 = stack->data;
else {
printf("Invalid expression.\n");
exit(1);
}
stack = pop(stack);
switch (prefix[i])
{
case '+':
stack = push(stack, operand1 + operand2);
break;
case '-':
stack = push(stack, operand1 - operand2);
break;
case '*':
stack = push(stack, operand1 * operand2);
break;
case '/':
if (operand2 != 0)
stack = push(stack, operand1 / operand2);
else {
printf("Division by zero is not allowed.\n");
exit(1);
}
break;
default:
printf("Invalid expression.\n");
exit(1);
}
}
}
if (!isEmpty(stack)) {
int result = stack->data;
stack = pop(stack);
return result;
}
else
{
printf("Invalid expression.\n");
exit(1);
}
}
int main()
{
char prefix[100];
printf("Enter the prefix expression: ");
scanf("%s", prefix);
int result = evaluatePrefixExpression(prefix);
printf("Result: %d \n", result);
return 0;
}

