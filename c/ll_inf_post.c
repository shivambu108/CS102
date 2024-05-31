//SHIVAMBU DEV PANDEY
//23BCS123
//CSE B
//LAB 7
//PROGRAM 3
//Date: 22/02/2024

/*
3.Write a C program to convert a given infix expression to its postfix equivalent using the stack. 
Implement the stack using the singly linked list data structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(char item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow.");
        exit(1);
    } else {
        char item = top->data;
        Node* temp = top;
        top = top->next;
        free(temp);
        return item;
    }
}

int is_operator(char symbol) {
    return (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-');
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infixToPostfix(char infix_exp[], char postfix_exp[]) {
    int i, j;
    char item;
    char x;
    push('(');
    strcat(infix_exp, ")");
    i = 0;
    j = 0;
    item = infix_exp[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } else if (isdigit(item) || isalpha(item)) {
            postfix_exp[j] = item;
            j++;
        } else if (is_operator(item) == 1) {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item)) {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        } else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        } else {
            printf("\nInvalid infix Expression.\n");
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    postfix_exp[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    int choice;

    do {
        printf("\nMenu\n");
        printf("1. Enter Infix expression and convert to Postfix\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Infix expression : ");
                scanf(" %[^\n]", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;
            case 2:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 2);

    return 0;
}
