#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node createNode(int data) {
    Node newNode;
    newNode.data = data;
    newNode.prev = NULL;
    newNode.next = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void findMinMax(Node* head, int* max, int* min) {
    if (head == NULL) {
        printf("Doubly linked list is empty\n");
        return;
    }

    *max = *min = head->data;
    Node* current = head;

    while (current != NULL) {
        if (current->data > *max) {
            *max = current->data;
        }

        if (current->data < *min) {
            *min = current->data;
        }

        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    int max, min, n, data;

    printf("Enter the number of elements in the doubly linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    findMinMax(head, &max, &min);

    printf("Doubly Linked List:\n");
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n");

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
