#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert() {
    int item;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow! Cannot insert element.\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);
    cq[rear] = item;

    printf("Element %d inserted successfully.\n", item);
}

void delete() {
    if (front == -1) {
        printf("Queue Empty! Cannot delete element.\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}


void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements are: ");

    if (front <= rear) {
        for (i = front; i <= rear; i++) {
            printf("%d ", cq[i]);
        }
    } else {
        for (i = front; i < MAX; i++) {
            printf("%d ", cq[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", cq[i]);
        }
    }
    printf("\n");
}


int main() {
    int choice = 0;

    while (choice != 4) {
        printf("\n--- CIRCULAR QUEUE OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            insert();
        else if (choice == 2)
            delete();
        else if (choice == 3)
            display();
        else if (choice == 4)
            printf("Exiting program.\n");
        else
            printf("Invalid choice! Try again.\n");
    }

    return 0;
}
