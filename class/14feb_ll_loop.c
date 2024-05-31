//write a program in c to implement circular check in linked list 

// for example if the user inputs 3,2,0,4 and 4 is linked back to 2 , return circular . Use linked lists

/*1.traverse through the linked list. maintain visit records . If the the liked list is cyclic you will find the element again. 
Else if the element is not in the list , add it to the visited record
*/
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

// Function to detect loop in a linked list
int detectLoop(struct Node *head) {
    struct Node *slow_p = head, *fast_p = head;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    // Creating a linked list
    push(&head, 4);
    push(&head, 0);
    push(&head, 2);
    push(&head, 3);

    // Making the linked list circular
    struct Node* temp = head;
    while(temp->data != 2) {
        temp = temp->next;
    }
    head->next->next->next->next = temp;

    if (detectLoop(head))
        printf("The linked list is circular.\n");
    else
        printf("The linked list is not circular.\n");

    return 0;
}
