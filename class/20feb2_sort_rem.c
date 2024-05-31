//write a program in c to sort a single linked list . after sorting the program should be able to remove duplicate elements

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void insert_end(Node** head, int item) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* p = *head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = new_node;
}

void display_ll(Node *head) {
    Node* p = head;
    while (p!=NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL");
}

void rem_dup(Node* head) {
    Node* p = head;
    Node* next_next; 
   
    if (p == NULL) 
       return; 
 
    while (p->next != NULL) {
       if (p->data == p->next->data) {            
           next_next = p->next->next;
           free(p->next);
           p->next = next_next;  
       }
       else {
          p = p->next; 
       }
    }
}

void sort_ll(Node *head) {
    int flag, i;
    Node *p;
    Node *q = NULL;

    if (head == NULL)
        return;
 
    do {
        flag = 0;
        p = head;
 
        while (p->next != q) {
            if (p->data > p->next->data) { 
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                flag = 1;
            }
            p = p->next;
        }
        q = p;
    }
    while (flag); // If no two elements were swapped by inner loop, then break 
}

int main() {
    Node* head = NULL;
 
    insert_end(&head, 33);
    insert_end(&head, 22);
    insert_end(&head, 55); 
    insert_end(&head, 22);
    insert_end(&head, 99);
    insert_end(&head, 33);                                    

    printf("Linked list");
    printf("Before sorting and removing duplicates \n");
    display_ll(head);
 
    sort_ll(head);
    rem_dup(head);
 
    printf("\nAfter sorting and removing duplicates \n");
    display_ll(head);           
    
    return 0;
}
