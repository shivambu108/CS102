#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

void traverse(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *p = head;

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);

    printf("\n");
}

node* create_node(int item) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_end(node **head, int item) {
    node *new_node = create_node(item);

    if (*head == NULL) {
        *head = new_node;
        (*head)->next = *head;
        (*head)->prev = *head;
        return;
    }

    node *last = (*head)->prev;
    last->next = new_node;
    new_node->prev = last;
    new_node->next = *head;
    (*head)->prev = new_node;
}

void delete_even_nodes(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *p = *head;
    node *temp;

    do {
        if (p->data % 2 == 0) {
            if (p->prev != NULL) {
                p->prev->next = p->next;
            } else {
                *head = p->next;
            }

            if (p->next != NULL) {
                p->next->prev = p->prev;
            }

            temp = p;
            p = p->next;
            free(temp);
        } else {
            p = p->next;
        }
    } while (p->next != *head);
}

int main() {
    node *head = NULL;
    int item;

    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);
    insert_end(&head, 50);

    printf("Original Circular Doubly Linked List:\n");
    traverse(head);

    delete_even_nodes(&head);

    printf("\nAfter deleting even nodes:\n");
    traverse(head);

    return 0;
}
