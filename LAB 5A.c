include <stdio.h>

include <stdlib.h>

struct Node { int data; struct Node *next; };

struct Node *head = NULL;

void create(int value) { struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

newnode->data = value;
newnode->next = NULL;

if (head == NULL) {
    head = newnode;
}
else {
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

printf("Node inserted : %d\n", value);


}

void deleteFirst() { if (head == NULL) { printf("List is Empty\n"); return; }

struct Node *temp = head;
head = head->next;
printf("Deleted first element : %d\n", temp->data);
free(temp);


}

void deleteLast() { if (head == NULL) { printf("List is Empty\n"); return; }

if (head->next == NULL) {
    printf("Deleted last element : %d\n", head->data);
    free(head);
    head = NULL;
    return;
}

struct Node *temp = head;
struct Node *prev = NULL;

while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
}

printf("Deleted last element : %d\n", temp->data);
prev->next = NULL;
free(temp);


}

void deleteSpecific(int value) { if (head == NULL) { printf("List is Empty\n"); return; }

struct Node *temp = head, *prev = NULL;

if (head->data == value) {
    head = head->next;
    printf("Deleted element : %d\n", value);
    free(temp);
    return;
}

while (temp != NULL && temp->data != value) {
    prev = temp;
    temp = temp->next;
}

if (temp == NULL) {
    printf("Element %d not found\n", value);
    return;
}

prev->next = temp->next;
printf("Deleted element : %d\n", value);
free(temp);


}

void display() { if (head == NULL) { printf("List is Empty\n"); return; }

struct Node *temp = head;
printf("Linked List : ");
while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
}
printf("NULL\n");


}

int main() { int choice, value;

while (1) {
   printf("\nSingly Linked List Menu\n");

printf("1. Create (Insert Element)\n");
   printf("2. Delete First Element\n");
    printf("3. Delete specific element\n");
    printf("4. Delete last element\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter value to insert : ");
            scanf("%d", &value);
            create(value);
            break;

        case 2:
            deleteFirst();
            break;

        case 3:
            printf("Enter value to delete : ");
            scanf("%d", &value);
            deleteSpecific(value);
            break;

        case 4:
            deleteLast();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again\n");
    }
}

return 0;


}
