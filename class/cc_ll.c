#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of a linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

// Function to check if a linked list is circular
int isCircular(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL && temp->next != head)
        temp = temp->next;
    return (temp == NULL) ? 0 : 1;
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    // Creating a linked list
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    // Making the linked list circular
    head->next->next->next->next = head;

    if (isCircular(head))
        printf("The linked list is circular\n");
    else
        printf("The linked list is not circular\n");

    return 0;
}
