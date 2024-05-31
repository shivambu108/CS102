#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

void traverse(node *head) {
    int count_f = 1;
    int count_r = 1;  
    node *p_f = head;
    node *p_r = head;

    printf("\nDoubly Linked List (Forward):\n");
    while (p_f != NULL) {
        printf("  Node_%d: %d\n", count_f, p_f->data);
        count_f++;
        p_f = p_f->next;
    }

    printf("\nDoubly Linked List (Reverse):\n");
    while (p_r != NULL && p_r->next != NULL) {
        p_r = p_r->next;
    }

    while (p_r != NULL) {
        printf("  Node_%d: %d\n", count_r, p_r->data);
        count_r++;
        p_r = p_r->prev;
    }
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
        return;
    }

    node *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = new_node;
    new_node->prev = p;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_asc(node *head) {
    node *current = head;
    while (current != NULL) {
        node *index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                swap(&(current->data), &(index->data));
            }
            index = index->next;
        }
        current = current->next;
    }
}

void sort_desc(node *head) {
    node *current = head;
    while (current != NULL) {
        node *index = current->next;
        while (index != NULL) {
            if (current->data < index->data) {
                swap(&(current->data), &(index->data));
            }
            index = index->next;
        }
        current = current->next;
    }
}

int display_menu() {
    int choice;
    
    printf("\nDoubly Linked List:\n");
    printf("1. Insert at end ");
    printf("2. Sort in ascending order\n");
    printf("3. Sort in descending order\n");
    printf("4. Traverse ");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    node *head = NULL;
    int choice, item;

    while(1) {
        choice = display_menu();

        switch(choice) {
            case 1:
                printf("Enter the item to be inserted at the end: ");
                scanf("%d", &item);
                insert_end(&head, item);
                break;
            case 2:
                sort_asc(head);
                break;
            case 3:
                sort_desc(head);
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
