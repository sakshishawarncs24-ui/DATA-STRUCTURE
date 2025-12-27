#include <stdio.h>

 #include <stdlib.h>

struct Node {

int data;

struct Node *prev;

struct Node *next;

 };

struct Node *head = NULL;

 struct Node *tail = NULL;

struct Node* createNode(int value) {

 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

 newNode->data = value;

 newNode->prev = NULL;

newNode->next = NULL;

return newNode;

 }

void insertLeft(int value, int targetValue) {

struct Node* newNode = createNode(value);

if (head == NULL) {
    head = tail = newNode;
    return;
}

struct Node* current = head;

while (current != NULL && current->data != targetValue) {
    current = current->next;
}

if (current == NULL) {
    printf("Target value not found\n");
    free(newNode);
    return;
}

if (current == head) {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return;
}

newNode->next = current;
newNode->prev = current->prev;
current->prev->next = newNode;
current->prev = newNode;


}

void deleteNode(int value) {

if (head == NULL) {

 printf("List is empty\n");

return;

 }

struct Node* current = head;

while (current != NULL && current->data != value) {
    current = current->next;
}

if (current == NULL) {
    printf("Value not found\n");
    return;
}

if (head == tail) {
    head = tail = NULL;
    free(current);
    return;
}

if (current == head) {
    head = head->next;
    head->prev = NULL;
    free(current);
    return;
}

// Case: Delete tail
if (current == tail) {
    tail = tail->prev;
    tail->next = NULL;
    free(current);
    return;
}


current->prev->next = current->next;
current->next->prev = current->prev;
free(current);


}

void display() { struct Node* current = head;

if (current == NULL) {
    printf("List is empty\n");
    return;
}

printf("List: ");
while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
}
printf("\n");


}

int main() {

int choice, value, target;

while (1) {
    printf("\n--- Doubly Linked List Menu ---\n");
    printf("1. Insert Left of Node\n");
    printf("2. Delete Node by Value\n");
    printf("3. Display List\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter target value to insert LEFT of: ");
            scanf("%d", &target);
            insertLeft(value, target);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
    }
}

return 0;


}
