

#include <stdio.h>

#include <stdlib.h>



#define MAX 5



int queue[MAX];

int front = -1, rear = -1;





void insert() {

    int item;



    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {

        printf("\nCircular Queue Overflow! Cannot insert element.\n");

        return;

    }



    printf("\nEnter element to insert: ");

    scanf("%d", &item);



    if (front == -1) {

        front = rear = 0;

    }

    else if (rear == MAX - 1) {

        rear = 0;

    }

    else {

        rear++;

    }



    queue[rear] = item;

    printf("Element %d inserted successfully.\n", item);

}





void delete() {

    if (front == -1) {

        printf("\nCircular Queue is Empty! Cannot delete element.\n");

        return;

    }



    printf("\nDeleted element: %d\n", queue[front]);



    if (front == rear) {

        front = rear = -1;

    }

    else if (front == MAX - 1) {

        front = 0;

    }

    else {

        front++;

    }

}



void display() {

    int i;



    if (front == -1) {

        printf("\nCircular Queue is Empty.\n");

        return;

    }



    printf("\nCircular Queue elements are:\n");



    if (front <= rear) {

        for (i = front; i <= rear; i++) {

            printf("%d ", queue[i]);

        }

    } else {

        for (i = front; i < MAX; i++) {

            printf("%d ", queue[i]);

        }

        for (i = 0; i <= rear; i++) {

            printf("%d ", queue[i]);

        }

    }

    printf("\n");

}



int main() {

    int choice;



    while (1) {

        printf("\n--- CIRCULAR QUEUE OPERATIONS ---");

        printf("\n1. Insert");

        printf("\n2. Delete");

        printf("\n3. Display");

        printf("\n4. Exit");

        printf("\nEnter your choice: ");

        scanf("%d", &choice);



        switch (choice) {

            case 1: insert();

                    break;

            case 2: delete();

                    break;

            case 3: display();

                    break;

            case 4: printf("\nExiting program.\n");

                    exit(0);

            default: printf("\nInvalid choice! Try again.\n");

        }

    }



    return 0;

}













