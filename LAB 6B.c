#include <stdio.h>

 #include <stdlib.h>

struct Node {

 int data;

 struct Node* next;

 };

struct Node* createNode(int value) {

struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

newNode->data = value;

newNode->next = NULL;

return newNode; }

struct Node* push(struct Node* top, int value) {

 struct Node* newNode = createNode(value);

 newNode->next = top;

return newNode; }

struct Node* pop(struct Node* top) {

 if (top == NULL) {

printf("Stack Underflow\n");

return NULL;

 }

struct Node* temp = top;
top = top->next;
printf("Popped: %d\n", temp->data);
free(temp);

return top;


}

void displayStack(struct Node* top) {

 printf("Stack: ");

while (top != NULL) {

printf("%d -> ", top->data);

top = top->next; }

printf("NULL\n");

}

void enqueue(struct Node** front, struct Node** rear, int value) {

 struct Node* newNode = createNode(value);

if (*rear == NULL) {
    *front = *rear = newNode;
    return;

}
(*rear)->next = newNode;
*rear = newNode;


}

void dequeue(struct Node** front, struct Node** rear) {

if (*front == NULL) {

printf("Queue Underflow\n");

return;

}

struct Node* temp = *front;
printf("Dequeued: %d\n", temp->data);

*front = (*front)->next;
if (*front == NULL)
    *rear = NULL;

free(temp);


}

void displayQueue(struct Node* front) {

 printf("Queue: ");

while (front != NULL) {

printf("%d -> ", front->data);

front = front->next;

 }

printf("NULL\n");

 }

int main() {

struct Node* stackTop = NULL;

printf("=== STACK OPERATIONS ===\n");
stackTop = push(stackTop, 10);
stackTop = push(stackTop, 20);
stackTop = push(stackTop, 30);

displayStack(stackTop);

stackTop = pop(stackTop);
displayStack(stackTop);


struct Node *front = NULL, *rear = NULL;

printf("\n=== QUEUE OPERATIONS ===\n");
enqueue(&front, &rear, 5);
enqueue(&front, &rear, 15);
enqueue(&front, &rear, 25);

displayQueue(front);

dequeue(&front, &rear);
displayQueue(front);

return 0;


}
