#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void traverse(node *head) {
    int count = 1;
    node *p = head;
    while (p != NULL) {
        printf("\nNode_%d _data: %d", count, p->data);
        count++;
        p = p->next;
    }
}

void insert_end(node **head, int item) {
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = item;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *p = *head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = new_node;
}

void swap(node **head) {
    node *current = *head;
    while (current != NULL && current->next != NULL) {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        current = current->next->next;
    }
}

int main() {
    node *head = NULL;
    int choice, item;

    while(1) {
        printf("\nSingly Linked List\n");
        printf("1. Insert at end ");
        printf("2. Swap adjacent nodes\n");
        printf("3. Traverse ");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insert_end(&head, item);
                break;
            case 2:
                swap(&head);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
