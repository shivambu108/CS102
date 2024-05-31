/*
wap in c to take number in decimal, convert in given base and the insert in linked list
ex. i/p :digit =15 , base = 2
    o/p : 1,2 ->1,2 ->1,2 ->1,2 ->NULL
         (digit),(base),(next)
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int digit;
    int base;
    struct node *next;
} node;

node* createNode(int digit, int base) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->digit = digit;
    newNode->base = base;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(node** head, int digit, int base) {
    node* newNode = createNode(digit, base);
    newNode->next = *head;
    *head = newNode;
}

void convertAndInsert(node** head, int num, int base) {
    while (num > 0) {
        insertAtFront(head, num % base, base);
        num = num / base;
    }
}

void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d,%d -> ", temp->digit, temp->base);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int num, base;

    // Taking input from the user
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("Enter the base: ");
    scanf("%d", &base);

    node* head = NULL;
    convertAndInsert(&head, num, base);
    printList(head);

    return 0;
}
