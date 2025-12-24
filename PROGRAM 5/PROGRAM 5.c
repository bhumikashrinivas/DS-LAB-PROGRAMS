#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
} *head = NULL;
int count() {
    struct node *temp = head;
    int c = 0;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}
struct node *create(int value) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}
void insert_begin(int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    head = newnode;
}
void delete_begin() {
    struct node *temp;
    if (head == NULL) {
        printf("Deletion not possible\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}
void delete_end() {
    struct node *temp, *prev;
    if (head == NULL) {
        printf("Deletion not possible\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}
void delete_pos(int pos) {
    struct node *temp, *prev;
    int i;
    if (pos < 1 || pos > count()) {
        printf("Deletion not possible\n");
        return;
    }
    if (pos == 1) {
        delete_begin();
        return;
    }
    temp = head;
    for (i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}
void delete_spec_value(int key) {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Element %d deleted\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Element %d deleted\n", key);
}
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int ch = 0, value, pos, key;
    while (ch != 7) {
        printf("Name:BHUMIKA SHRINIVAS TELI\nUSN: 1BM24CS072\n");
        printf("\n1. Insert begin");
        printf("\n2. Delete begin");
        printf("\n3. Delete end");
        printf("\n4. Delete position");
        printf("\n5. Delete key");
        printf("\n6. Display");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_begin(value);
            break;

        case 2:
            delete_begin();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 5:
            printf("Enter key: ");
            scanf("%d", &key);
            delete_spec_value(key);
            break;
        case 6:
            display();
            break;
        case 7:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
