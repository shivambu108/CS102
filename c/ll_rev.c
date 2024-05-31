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
void rev_ll(Node **head) {
    Node *p = *head;
    Node *r = NULL;
    Node *q = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
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
    diplay(head);

    rev_ll(&head);

    printf("\nReversed Linked List:\n");
    diplay(head);

    free_ll(head);

    return 0;
}
