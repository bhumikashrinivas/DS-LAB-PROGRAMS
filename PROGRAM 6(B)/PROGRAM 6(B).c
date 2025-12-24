#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *stack_top = NULL;
struct node *queue_front = NULL;
struct node *queue_rear = NULL;

void push(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = stack_top;
    stack_top = newnode;
    printf("%d pushed to stack.\n", value);
}

int pop() {
    if (stack_top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct node *temp = stack_top;
    int val = temp->data;
    stack_top = temp->next;
    free(temp);
    return val;
}

int peek_stack() {
    if (stack_top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack_top->data;
}

void display_stack() {
    struct node *cur = stack_top;
    if (cur == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void enqueue(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (queue_front == NULL) {
        queue_front = queue_rear = newnode;
    } else {
        queue_rear->next = newnode;
        queue_rear = newnode;
    }
}

int dequeue() {
    if (queue_front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }
    struct node *temp = queue_front;
    int val = temp->data;
    queue_front = temp->next;
    if (queue_front == NULL)
        queue_rear = NULL;

    free(temp);
    return val;
}

int peek_queue() {
    if (queue_front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue_front->data;
}

void display_queue() {
    struct node *cur = queue_front;
    if (cur == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
int main() {
    int option = 0, val, del, p;
    do {
        printf("Name:BHUMIKA SHRINIVAS TELI\nUSN: 1BM24CS072\n");
        printf("\n***** MAIN MENU *****");
        printf("\n1. Push (Stack)");
        printf("\n2. Pop (Stack)");
        printf("\n3. Peek (Stack)");
        printf("\n4. Display Stack");
        printf("\n5. Enqueue (Queue)");
        printf("\n6. Dequeue (Queue)");
        printf("\n7. Peek (Queue)");
        printf("\n8. Display Queue");
        printf("\n9. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            del = pop();
            if (del != -1)
                printf("Popped element: %d\n", del);
            break;
        case 3:
            p = peek_stack();
            if (p != -1)
                printf("Top element: %d\n", p);
            break;
        case 4:
            display_stack();
            break;
        case 5:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 6:
            del = dequeue();
            if (del != -1)
                printf("Dequeued element: %d\n", del);
            break;
        case 7:
            p = peek_queue();
            if (p != -1)
                printf("Front element: %d\n", p);
            break;
        case 8:
            display_queue();
            break;
        case 9:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option!\n");
        }
    } while (option != 9);
    return 0;
}
