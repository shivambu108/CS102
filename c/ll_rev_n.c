#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert_end(Node **head, int item) {
   Node *new_node = (Node*) malloc(sizeof(Node));
   new_node->data = item;
   new_node->next = NULL;
   if (*head == NULL) {
       *head = new_node;
       return;
   }
   Node *p = *head;
   while(p->next != NULL) {
       p = p->next;
   }
   p->next = new_node;
}

void rev_first_n(Node **head, int n) {
    Node *p = *head;
    Node *r = NULL;
    Node *q = NULL;
    int count = 0;

    while (p != NULL && count < n) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        count++;
    }

    if (*head != NULL) {
        (*head)->next = p;
    }

    *head = q;
}

void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_ll(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    int n, value;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_end(&head, value);
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    int m;
    printf("\nEnter the number of elements to reverse from the beginning of the linked list: ");
    scanf("%d", &m);

    rev_first_n(&head, m);

    printf("\nLinked List after reversing the first %d elements:\n", m);
    display(head);

    free_ll(head);

    return 0;
}
