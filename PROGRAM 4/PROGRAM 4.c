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
 void insert_end(int value) {
    struct node *newnode = create(value);
    struct node *temp;
   if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insert_pos(int value, int pos) {
    struct node *newnode, *temp;
    int i;
    if (pos < 1 || pos > count() + 1) {
        printf("Insertion not possible\n");
        return;
    }
  if (pos == 1) {
        insert_begin(value);
        return;
    }
  newnode = create(value);
    temp = head;
  for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
 newnode->next = temp->next;
    temp->next = newnode;
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
    int ch = 0, value, pos;
 while (ch != 5) {
       printf("Name:BHUMIKA SHRINIVAS TELI\nUSN: 1BM24CS072\n");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
   switch (ch) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_begin(value);
            break;
       case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_end(value);
            break;
       case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert_pos(value, pos);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
