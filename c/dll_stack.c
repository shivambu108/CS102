#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

typedef struct stack {
    node *top;
} stack;

void push(stack *s, int item) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = s->top;

    if (s->top != NULL) {
        s->top->prev = new_node;
    }

    s->top = new_node;
}

int pop(stack *s) {
    if (s->top == NULL) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    int popped_item = s->top->data;
    node *temp = s->top;
    s->top = s->top->next;

    if (s->top != NULL) {
        s->top->prev = NULL;
    }

    free(temp);
    return popped_item;
}

void display_stack(stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    node *p = s->top;
    printf("Stack elements:\n");
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main() {
    stack myStack;
    myStack.top = NULL;

    int choice, item;

    while(1) {
        printf("\nStack (using Doubly Linked List):\n");
        printf("1. Push ");
        printf("2. Pop ");
        printf("3. Display ");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                push(&myStack, item);
                break;
            case 2:
                printf("Popped element: %d\n", pop(&myStack));
                break;
            case 3:
                display_stack(&myStack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
