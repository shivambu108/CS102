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

void insert_begin(node **head, int item) {
    node *new_node = create_node(item);
    new_node->next = *head;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    *head = new_node;
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

void insert_any_position(node **head, int item, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    node *new_node = create_node(item);
 
     if (pos == 1) {
        new_node->next = *head;

        if (*head != NULL) {
            (*head)->prev = new_node;
        }

        *head = new_node;
        return;
    }

    node *p = *head;
    for (int i = 1; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Position out of range\n");
        free(new_node);
        return;
    }

    new_node->next = p->next;
    new_node->prev = p;
    
    if (p->next != NULL) {
        p->next->prev = new_node;
    }

    p->next = new_node;
}

void delete_begin(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

void delete_end(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *p = *head, *q = NULL;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }

    if (q != NULL) {
        q->next = NULL;
    } else {
        *head = NULL;
    }

    free(p);
}

void delete_any_pos(node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *p = *head, *q = NULL;
    if (pos == 1) {
        *head = p->next;

        if (*head != NULL) {
            (*head)->prev = NULL;
        }

        free(p);
        return;
    }

    for (int i = 1; i < pos && p != NULL; i++) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("Position out of range\n");
        return;
    }

    q->next = p->next;
    
    if (p->next != NULL) {
        p->next->prev = q;
    }

    free(p);
}

int display_menu() {
    int choice;
    
    printf("\nDoubly Linked List:\n");
    printf("1. Insert at beginning   ");
    printf("2. Insert at end ");
    printf("3. Insert at any position\n");
    printf("4. Delete from beginning ");
    printf("5. Delete from end ");
    printf("6. Delete from any position\n");
    printf("7. Traverse ");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    node *head = NULL;
    int choice, item, pos;

    while(1) {
        choice = display_menu();

        switch(choice) {
            case 1:
                printf("Enter the item to be inserted at the beginning: ");
                scanf("%d", &item);
                insert_begin(&head, item);
                break;
            case 2:
                printf("Enter the item to be inserted at the end: ");
                scanf("%d", &item);
                insert_end(&head, item);
                break;
            case 3:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                printf("Enter the position at which to insert: ");
                scanf("%d", &pos);
                insert_any_position(&head, item, pos);
                break;
            case 4:
                delete_begin(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                printf("Enter the position at which to delete: ");
                scanf("%d", &pos);
                delete_any_pos(&head, pos);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
