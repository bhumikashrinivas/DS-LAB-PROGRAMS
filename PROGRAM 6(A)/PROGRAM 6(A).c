#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *create(int value);
struct node *insert_beg(struct node *head, int value);
void display(struct node *head);
struct node *reverse_list(struct node *head);
struct node *sort_list(struct node *head);
struct node *concat_lists(struct node *head1, struct node *head2);
struct node *create(int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}
struct node *insert_beg(struct node *head, int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    return newnode;
}

void display(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct node *reverse_list(struct node *head) {
    struct node *prev = NULL, *current = head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
struct node *sort_list(struct node *head) {
    struct node *ptr1, *lptr = NULL;
    int swapped;
    if (head == NULL)
        return head;
    while (1) {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
        if (!swapped)
            break;
    }
    return head;
}
struct node *concat_lists(struct node *head1, struct node *head2) {
    struct node *temp = head1;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int m, n, val, i;
    printf("Name:BHUMIKA SHRINIVAS TELI\nUSN: 1BM24CS072\n");
    printf("Enter no. of nodes in the lists:\n");
    scanf("%d %d", &m, &n);
    printf("Enter values for list 1:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        head1 = insert_beg(head1, val);
    }
    printf("List 1 is: ");
    display(head1);
    printf("Enter values for list 2:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        head2 = insert_beg(head2, val);
    }
    printf("List 2 is: ");
    display(head2);
    head1 = reverse_list(head1);
    printf("Reversed List 1 is: ");
    display(head1);
    head2 = sort_list(head2);
    printf("Sorted List 2 is: ");
    display(head2);
    struct node *concat_head = concat_lists(head1, head2);
    printf("Concatenated List is: ");
    display(concat_head);

    return 0;
}


