#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void enqueue(queue *q, int item) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        new_node->prev = q->rear;
        q->rear = new_node;
    }
}

int dequeue(queue *q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }

    int dequeued_item = q->front->data;
    node *temp = q->front;
    
    q->front = q->front->next;
    if (q->front != NULL) {
        q->front->prev = NULL;
    } else {
        q->rear = NULL;  // Queue is empty after dequeue
    }

    free(temp);
    return dequeued_item;
}

void display_queue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *p = q->front;
    printf("Queue elements:\n");
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main() {
    queue Q;
    Q.front = NULL;
    Q.rear = NULL;

    int choice, item;

    while(1) {
        printf("\nQueue (using Doubly Linked List):\n");
        printf("1. Enqueue ");
        printf("2. Dequeue ");
        printf("3. Display ");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the item to be enqueued: ");
                scanf("%d", &item);
                enqueue(&Q, item);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(&Q));
                break;
            case 3:
                display_queue(&Q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
