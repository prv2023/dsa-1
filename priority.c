#include <stdio.h>
#include <stdlib.h>
struct PriorityQueueNode {
int data;
int priority;
struct PriorityQueueNode* next;
};
struct PriorityQueue {
struct PriorityQueueNode* front;
};
void initializePriorityQueue(struct PriorityQueue* pq) {
pq->front = NULL;
}
int isEmpty(struct PriorityQueue* pq) {
return (pq->front == NULL);
}
struct PriorityQueueNode* createNode(int data, int priority) {
struct PriorityQueueNode* newNode = (struct PriorityQueueNode*)malloc(sizeof(struct
PriorityQueueNode));
newNode->data = data;
newNode->priority = priority;
newNode->next = NULL;
return newNode;
}
void enqueue(struct PriorityQueue* pq, int data, int priority) {
struct PriorityQueueNode* newNode = createNode(data, priority);
if (isEmpty(pq) || priority < pq->front->priority) {
newNode->next = pq->front;
pq->front = newNode;
} else {
struct PriorityQueueNode* temp = pq->front;
while (temp->next != NULL && temp->next->priority <= priority) {
temp = temp->next;
}
newNode->next = temp->next;
temp->next = newNode;
}
}
void dequeue(struct PriorityQueue* pq) {
if (isEmpty(pq)) {
printf("Priority Queue is empty. Cannot dequeue.\n");
return;
}
struct PriorityQueueNode* temp = pq->front;
pq->front = pq->front->next;
free(temp);
}
void displayPriorityQueue(struct PriorityQueue* pq) {
if (isEmpty(pq)) {
printf("Priority Queue is empty.\n");
return;
}
printf("Priority Queue: ");
struct PriorityQueueNode* temp = pq->front;
while (temp != NULL) {
printf("(%d, %d) ", temp->data, temp->priority);
temp = temp->next;
}
printf("\n");
}
int main()
{
struct PriorityQueue pq;
initializePriorityQueue(&pq);
int data, priority;
printf("Enter data: ");
scanf("%d", &data);
printf("Enter priority: ");
scanf("%d", &priority);
enqueue(&pq, data, priority);
displayPriorityQueue(&pq);
dequeue(&pq);
displayPriorityQueue(&pq);
return 0;
}