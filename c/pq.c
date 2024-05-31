#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int priority;
    struct node *next;
} node;

void traverse(node *head) {
    int count = 1;
    node *p = head;
    while (p != NULL) {
        printf("\nNode_%d _data: %d (Priority: %d)", count, p->data, p->priority);
        count++;
        p = p->next;
    }
}

void insert_priority(node **head, int item, int priority) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    new_node->priority = priority;

    if (*head == NULL || priority > (*head)->priority) {
        new_node->next = *head;
        *head = new_node;
    } else {
        node *p = *head;
        while (p->next != NULL && p->next->priority >= priority) {
            p = p->next;
        }
        new_node->next = p->next;
        p->next = new_node;
    }
}

void delete_highest_priority(node **head) {
    if (*head == NULL) {
        printf("Priority queue is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    node *head = NULL;
    int choice, item, priority;

    while (1) {
        printf("\nPriority Queue using Linked List\n");
        printf("1. Insert with Priority   ");
        printf("2. Delete Highest Priority ");
        printf("3. Traverse ");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                printf("Enter the priority: ");
                scanf("%d", &priority);
                insert_priority(&head, item, priority);
                break;
            case 2:
                delete_highest_priority(&head);
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
